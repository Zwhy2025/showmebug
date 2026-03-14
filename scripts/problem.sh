#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$ROOT_DIR/src"
TEMPLATE_DIR="$ROOT_DIR/templates/src"
PROBLEMS_DIR="$ROOT_DIR/problems"
CURRENT_DIR="$PROBLEMS_DIR/_current"

usage() {
    cat <<'EOF'
Usage:
  ./scripts/problem.sh start <slug> [title]    Start a problem from template or restore existing backup
  ./scripts/problem.sh save <slug> [title]     Save current src/ as a problem backup
  ./scripts/problem.sh restore <slug>          Restore a saved problem into src/
  ./scripts/problem.sh reset                   Reset src/ to the default template
  ./scripts/problem.sh list                    List saved problems
  ./scripts/problem.sh current                 Show the latest auto-saved current snapshot

Examples:
  ./scripts/problem.sh start palindrome-linked-list "回文链表"
  ./scripts/problem.sh save palindrome-linked-list "回文链表"
  ./scripts/problem.sh restore palindrome-linked-list
  ./scripts/problem.sh reset
EOF
}

timestamp() {
    date '+%Y-%m-%d %H:%M:%S %z'
}

escape_sed_replacement() {
    printf '%s' "$1" | sed 's/[\/&]/\\&/g'
}

ensure_layout() {
    mkdir -p "$PROBLEMS_DIR" "$CURRENT_DIR" "$TEMPLATE_DIR"

    if [[ ! -f "$SRC_DIR/main.cpp" || ! -f "$SRC_DIR/solution.hpp" ]]; then
        echo "Error: src/main.cpp or src/solution.hpp is missing." >&2
        exit 1
    fi

    if [[ ! -f "$TEMPLATE_DIR/main.cpp" || ! -f "$TEMPLATE_DIR/solution.hpp" ]]; then
        echo "Error: template files are missing under templates/src/." >&2
        exit 1
    fi
}

snapshot_current() {
    mkdir -p "$CURRENT_DIR"
    cp "$SRC_DIR/main.cpp" "$CURRENT_DIR/main.cpp"
    cp "$SRC_DIR/solution.hpp" "$CURRENT_DIR/solution.hpp"

    cat >"$CURRENT_DIR/meta.txt" <<EOF
slug=_current
title=Current workspace snapshot
saved_at=$(timestamp)
source=src
EOF
}

write_meta() {
    local problem_dir="$1"
    local slug="$2"
    local title="$3"

    cat >"$problem_dir/meta.txt" <<EOF
slug=$slug
title=$title
saved_at=$(timestamp)
EOF
}

copy_problem_to_src() {
    local problem_dir="$1"
    cp "$problem_dir/main.cpp" "$SRC_DIR/main.cpp"
    cp "$problem_dir/solution.hpp" "$SRC_DIR/solution.hpp"
}

save_problem() {
    local slug="$1"
    local title="${2:-$slug}"
    local problem_dir="$PROBLEMS_DIR/$slug"

    mkdir -p "$problem_dir"
    cp "$SRC_DIR/main.cpp" "$problem_dir/main.cpp"
    cp "$SRC_DIR/solution.hpp" "$problem_dir/solution.hpp"
    write_meta "$problem_dir" "$slug" "$title"

    echo "Saved current src/ to problems/$slug"
}

render_template_to_src() {
    local slug="$1"
    local title="$2"
    local escaped_slug
    local escaped_title

    escaped_slug="$(escape_sed_replacement "$slug")"
    escaped_title="$(escape_sed_replacement "$title")"

    sed \
        -e "s/__PROBLEM_SLUG__/$escaped_slug/g" \
        -e "s/__PROBLEM_TITLE__/$escaped_title/g" \
        "$TEMPLATE_DIR/main.cpp" >"$SRC_DIR/main.cpp"

    sed \
        -e "s/__PROBLEM_SLUG__/$escaped_slug/g" \
        -e "s/__PROBLEM_TITLE__/$escaped_title/g" \
        "$TEMPLATE_DIR/solution.hpp" >"$SRC_DIR/solution.hpp"
}

start_problem() {
    local slug="$1"
    local title="${2:-$slug}"
    local problem_dir="$PROBLEMS_DIR/$slug"

    snapshot_current

    if [[ -f "$problem_dir/main.cpp" && -f "$problem_dir/solution.hpp" ]]; then
        copy_problem_to_src "$problem_dir"
        echo "Restored problems/$slug into src/"
        return
    fi

    render_template_to_src "$slug" "$title"
    save_problem "$slug" "$title"
    echo "Initialized src/ from template for $slug"
}

restore_problem() {
    local slug="$1"
    local problem_dir="$PROBLEMS_DIR/$slug"

    if [[ ! -f "$problem_dir/main.cpp" || ! -f "$problem_dir/solution.hpp" ]]; then
        echo "Error: problems/$slug does not exist." >&2
        exit 1
    fi

    snapshot_current
    copy_problem_to_src "$problem_dir"
    echo "Restored problems/$slug into src/"
}

reset_problem() {
    snapshot_current
    render_template_to_src "scratch" "Scratch Pad"
    echo "Reset src/ to the default template"
}

list_problems() {
    if [[ ! -d "$PROBLEMS_DIR" ]]; then
        echo "No saved problems yet."
        return
    fi

    local found=0
    for dir in "$PROBLEMS_DIR"/*; do
        [[ -d "$dir" ]] || continue
        [[ "$(basename "$dir")" == "_current" ]] && continue
        found=1

        if [[ -f "$dir/meta.txt" ]]; then
            local slug
            local title
            local saved_at
            slug="$(grep '^slug=' "$dir/meta.txt" | cut -d'=' -f2-)"
            title="$(grep '^title=' "$dir/meta.txt" | cut -d'=' -f2-)"
            saved_at="$(grep '^saved_at=' "$dir/meta.txt" | cut -d'=' -f2-)"
            printf '%-30s | %-20s | %s\n' "$slug" "$title" "$saved_at"
        else
            echo "$(basename "$dir")"
        fi
    done

    if [[ "$found" -eq 0 ]]; then
        echo "No saved problems yet."
    fi
}

show_current() {
    if [[ ! -f "$CURRENT_DIR/main.cpp" || ! -f "$CURRENT_DIR/solution.hpp" ]]; then
        echo "No current snapshot yet."
        return
    fi

    if [[ -f "$CURRENT_DIR/meta.txt" ]]; then
        cat "$CURRENT_DIR/meta.txt"
    else
        echo "Current snapshot exists in problems/_current"
    fi
}

main() {
    ensure_layout

    local command="${1:-}"
    case "$command" in
    start)
        [[ $# -ge 2 ]] || {
            usage
            exit 1
        }
        start_problem "$2" "${3:-$2}"
        ;;
    save)
        [[ $# -ge 2 ]] || {
            usage
            exit 1
        }
        save_problem "$2" "${3:-$2}"
        ;;
    restore)
        [[ $# -eq 2 ]] || {
            usage
            exit 1
        }
        restore_problem "$2"
        ;;
    reset)
        [[ $# -eq 1 ]] || {
            usage
            exit 1
        }
        reset_problem
        ;;
    list)
        [[ $# -eq 1 ]] || {
            usage
            exit 1
        }
        list_problems
        ;;
    current)
        [[ $# -eq 1 ]] || {
            usage
            exit 1
        }
        show_current
        ;;
    *)
        usage
        exit 1
        ;;
    esac
}

main "$@"
