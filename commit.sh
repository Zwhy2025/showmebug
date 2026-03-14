#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

current_branch() {
    git -C "$ROOT_DIR" branch --show-current
}

main() {
    local branch_name
    local timestamp
    local message

    branch_name="$(current_branch)"
    if [[ -z "$branch_name" ]]; then
        echo "Error: not on a git branch." >&2
        exit 1
    fi

    if [[ -z "$(git -C "$ROOT_DIR" status --porcelain -- src)" ]]; then
        echo "No src changes to commit"
        exit 0
    fi

    timestamp="$(date '+%Y%m%d-%H%M%S')"
    message="${branch_name}/${timestamp}"

    git -C "$ROOT_DIR" add src
    git -C "$ROOT_DIR" commit -m "$message"
}

main "$@"
