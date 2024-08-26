#!/bin/sh

set -e; # exit on error

./scripts/clean.sh
./scripts/createBuildSkeleton.sh
./scripts/build.sh
