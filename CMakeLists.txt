cmake_minimum_required(VERSION 3.23)
project(cppstdlib)

set(CMAKE_CXX_STANDARD 14)

# 3 语言新特性
add_subdirectory(lang)
add_subdirectory(stl)
add_subdirectory(cont)
# 9 STL 迭代器
add_subdirectory(iter)
# 10 STL 函数对象及 Lambda
add_subdirectory(fo)