cmake_minimum_required(VERSION 3.22)

project(bank_secure)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

add_subdirectory(src)
