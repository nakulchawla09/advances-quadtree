cmake_minimum_required(VERSION 3.6)
project(advdbTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp QPoint.h QuadTree.h QuadTreeLib.h QBoundingBox.h QuadNode.h)
add_executable(advdbTest ${SOURCE_FILES} QPoint.h QuadTree.h QBoundingBox.h)