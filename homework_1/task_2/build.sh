#!/usr/bin/env bash

echo "Building process started..."

SRC_DIR=./src
BUILD_DIR=./build
INCLUDE_DIR=./include
RESULTS_DIR=./results

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
    echo "..create build dir.."
    mkdir -p "$BUILD_DIR"
fi

echo "..compile source files into object files.."
CXXFLAGS="-std=c++17 -I$INCLUDE_DIR"
c++ $CXXFLAGS -c "$SRC_DIR/sum.cpp" -o "$BUILD_DIR/sum.o"
c++ $CXXFLAGS -c "$SRC_DIR/subtract.cpp" -o "$BUILD_DIR/subtract.o"
c++ $CXXFLAGS -c "$SRC_DIR/main.cpp" -o "$BUILD_DIR/main.o"

echo "..create static library.."
ar rcs "$BUILD_DIR/libipb_arithmetic.a" "$BUILD_DIR/subtract.o" "$BUILD_DIR/sum.o"

echo "..link and create main executable.."
c++ $CXXFLAGS "$SRC_DIR/main.cpp" -L "$BUILD_DIR" -lipb_arithmetic -o "$BUILD_DIR/test_ipb_arithmetic"

# Check if the build directory exists
if [ ! -d "$RESULTS_DIR/bin" ] || [ ! -d "$RESULTS_DIR/lib" ]; then
    echo "..create results dir.."
    mkdir -p "$RESULTS_DIR/bin" "$RESULTS_DIR/lib"
fi

echo "..copying executable and libraries to results dir.."
cp -p "$BUILD_DIR/libipb_arithmetic.a" "$RESULTS_DIR/lib/"
cp -p "$BUILD_DIR/test_ipb_arithmetic"  "$RESULTS_DIR/bin/"

echo "Build process completed."
