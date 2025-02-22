#!/usr/bin/env bash

error () {
  echo "$1"
  exit 1
}

if ! cd ./build-debug/
then
   mkdir ./build-debug/
   cd ./build-debug/ || error "unable to create build director"
fi

cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
cd ..

