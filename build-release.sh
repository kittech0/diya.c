#!/usr/bin/env bash

error () {
  echo "$1"
  exit 1
}

if ! cd ./build-release/
then
   mkdir ./build-release/
   cd ./build-release/ || error "unable to create build director"
fi

cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cd ..

