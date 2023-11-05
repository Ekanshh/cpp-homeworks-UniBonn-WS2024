#!/usr/bin/env bash

SRC_DIR="./src"
INCLUDE_DIR="./include"
BUILD_DIR="./build"
RESULTS_DIR="./results"

echo "Building process started..."
mkdir -p "$BUILD_DIR" "$RESULTS_DIR/lib" "$RESULTS_DIR/bin"

echo "...creating source objects..."
CXXFLAGS="-std=c++17 -I$INCLUDE_DIR"
c++ $CXXFLAGS -c "$SRC_DIR/sum.cpp" -o "$BUILD_DIR/sum.o"
c++ $CXXFLAGS -c "$SRC_DIR/subtract.cpp" -o "$BUILD_DIR/subtract.o"
c++ $CXXFLAGS -c "$SRC_DIR/main.cpp" -o "$BUILD_DIR/main.o"

echo "...creating library..."
ar rcs "$BUILD_DIR/libipb_arithmetic.a" "$BUILD_DIR/subtract.o" "$BUILD_DIR/sum.o"

echo "...compiling main program..."
c++ $CXXFLAGS "$SRC_DIR/main.cpp" -L "$BUILD_DIR" -lipb_arithmetic -o "$BUILD_DIR/test_ipb_arithmetic"

echo "...copying files..."
cp "$BUILD_DIR/libipb_arithmetic.a" "$RESULTS_DIR/lib/"
cp "$BUILD_DIR/test_ipb_arithmetic"  "$RESULTS_DIR/bin/"

echo "Build process completed."
