cmake_minimum_required(VERSION 3.6)
project(advdbTest)

set(CMAKE_CXX_STANDARD 11)

<<<<<<< HEAD
set(SOURCE_FILES main.cpp QPoint.h QuadTree.h QuadTreeLib.h QBoundingBox.h QuadNode.h prQuadNode.h prQuadTree.h Test/testCases.h mxcifQuadNode.h mxcifQuadTree.h)
=======
set(SOURCE_FILES main.cpp QPoint.h QuadTreeLib.h QBoundingBox.h prQuadNode.h prQuadTree.h testCases.h mxcifQuadNode.h mxcifQuadTree.h)
>>>>>>> 0cf9f9bb025d357c2ad2b26f1ebc69f88623b8ab
add_executable(advdbTest ${SOURCE_FILES})