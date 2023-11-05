#!/usr/bin/env bash

echo "Building process started..."
mkdir -p build
c++ -std=c++17 -c ./src/sum.cpp -o ./build/sum.o -I ./include/
c++ -std=c++17 -c ./src/subtract.cpp -o ./build/subtract.o -I ./include/
c++ -std=c++17 -c ./src/main.cpp -o ./build/main.o -I ./include/
ar rcs ./build/libipb_arithmetic.a ./build/subtract.o ./build/sum.o 
c++ -std=c++17 ./src/main.cpp -L ./build/ -lipb_arithmetic -o ./build/test_ipb_arithmetic -I ./include/
cp ./build/libipb_arithmetic.a ./results/lib/
cp ./build/test_ipb_arithmetic  ./results/bin/
echo "finished."
