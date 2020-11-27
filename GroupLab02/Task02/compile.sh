#!/bin/bash

g++ ./source/main.cpp \
-o ./bin/worker \
-Wall \
./source/Date.cpp \
./source/Employee.cpp \
./source/ProductionWorker.cpp