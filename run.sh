#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"

if ! command -v cmake >/dev/null 2>&1; then
  echo "Error: cmake not found. Please install it (e.g., brew install cmake)." >&2
  exit 1
fi

cmake -S "$ROOT_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$BUILD_DIR"

"$BUILD_DIR/showmebug"
