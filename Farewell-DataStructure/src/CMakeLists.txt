cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 11)

add_executable(src main.cpp LinkList/LinkList.h Queue/PascalTriangle.h Search/BinarySearch.h Sort/BinaryInsertSort.h Sort/ShellSort.h)