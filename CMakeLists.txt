#cmake_minimum_required(VERSION 3.27)
cmake_minimum_required(VERSION 3.10)
project(compmath4)

set(CMAKE_CXX_STANDARD 17)

add_executable(compmath4 main.cpp
        functions/IFunc.h
        generator/Generator.cpp
        generator/Generator.h
        functions/func1.cpp
        functions/func1.h
        pregresion/Polynomial_regression.cpp
        pregresion/Polynomial_regression.h
        functions/Polynomial.cpp
        functions/Polynomial.h
        scaller/StandartScaller.cpp
        scaller/StandartScaller.h
)
