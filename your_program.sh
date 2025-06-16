#!/bin/sh
#
# Use this script to run your program LOCALLY.
#
# Note: Changing this script WILL NOT affect how CodeCrafters runs your program.
#
# Learn more: https://codecrafters.io/program-interface

set -e # Exit early if any commands fail

# Modified compile steps for MinGW environment
(
  cd "$(dirname "$0")" # Ensure compile steps are run within the repository directory
  
  # Set compiler environment variables
  export CC=gcc
  export CXX=g++
  
  # Use MinGW Makefiles generator and remove vcpkg dependency
  cmake -B build -S . -G "MinGW Makefiles"
  
  # Build using mingw32-make
  cd build && mingw32-make
)

# Run the program
exec $(dirname $0)/build/interpreter "$@"