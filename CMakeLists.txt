
cmake_minimum_required(VERSION 3.27)
project(Stm32ItmLogger)

file(GLOB_RECURSE SOURCES
        "src/*.*"
)

add_library(Stm32ItmLogger STATIC ${SOURCES})

target_include_directories(Stm32ItmLogger PUBLIC
        src
)
