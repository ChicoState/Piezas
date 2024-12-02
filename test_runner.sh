#!/bin/bash

make clean
make
./PiezasTest
gcov -rbc Piezas.cpp