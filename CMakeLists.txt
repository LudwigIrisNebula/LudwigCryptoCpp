cmake_minimum_required(VERSION 3.10)
project(LudwigCryptoCpp)

set(CMAKE_CXX_STANDARD 17)

# 可执行文件
add_executable(caesar_cipher src/classical/caesar.cpp)
add_executable(aes_demo src/modern/aes.cpp)
add_executable(affine_cipher src/classical/affine.cpp)