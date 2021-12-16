#!/bin/bash

make clean
make run
make

./parser ./test/test.c
