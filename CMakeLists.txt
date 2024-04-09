cmake_minimum_required(VERSION 3.27)
project(scan_eml C)

set(CMAKE_C_STANDARD 11)

add_executable(scan_eml src/main.c
        src/utils/validateFile.c
        include/validateFile.h
        src/utils/validatePesel.c
        include/validatePesel.h
        src/searchFile.c
        include/searchFile.h)
