cmake_minimum_required(VERSION 3.27)
project(Stm32ItmLogger C)

set(CMAKE_C_STANDARD 11)

add_library(Stm32ItmLogger STATIC Stm32ItmLogger.c)
