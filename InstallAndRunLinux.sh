#!/usr/bin/env bash


cd ProjectCode
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=.. -DBUILD_SHARED_LIBS=ON
make install

cd ../build
./TestCase
./QtProject
