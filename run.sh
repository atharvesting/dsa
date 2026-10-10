#!/usr/bin/env bash
# Quick-iterate runner: builds cp_main and pipes in.txt into it.
# Usage: ./run.sh [extra args...]   (input always comes from in.txt if it exists)
set -e
cd "$(dirname "$0")"
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug > /dev/null
cmake --build build --target cp_main
if [ -f in.txt ]; then
  ./build/cp_main "$@" < in.txt
else
  ./build/cp_main "$@"
fi
