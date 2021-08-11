cmake_minimum_required(VERSION 3.10.2)

project(AdditiveGaussianNoiseImageFilter)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(AdditiveGaussianNoiseImageFilter main.cpp)
target_link_libraries(AdditiveGaussianNoiseImageFilter ${ITK_LIBRARIES})