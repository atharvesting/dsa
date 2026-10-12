#!/usr/bin/env bash
# Quick-iterate runner: builds cp_main and pipes in.txt into it.
# Usage: ./run.sh [extra args...]   (input always comes from in.txt if it exists)
#        ./run.sh perf [extra args...]  -> Release (-O2) + -DONLINE_JUDGE build,
#           mirroring Codeforces compile flags; binary goes to build-perf/.
set -e
cd "$(dirname "$0")"
if [ "${1:-}" = "perf" ]; then
  shift
  DIR=build-perf
  cmake -S . -B "$DIR" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-DONLINE_JUDGE" > /dev/null
  cmake --build "$DIR" --target cp_main
else
  DIR=build
  cmake -S . -B "$DIR" -DCMAKE_BUILD_TYPE=Debug > /dev/null
  cmake --build "$DIR" --target cp_main
fi
if [ -f in.txt ]; then
  ./"$DIR"/cp_main "$@" < in.txt
else
  ./"$DIR"/cp_main "$@"
fi
