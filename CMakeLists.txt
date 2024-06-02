cmake_minimum_required(VERSION 3.27)
project(learnCplusplus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(learnCplusplus code/main.cpp
        code/Circle.cpp
        code/Circle.h
        code/Cube.cpp
        code/Cube.h
        code/Person.cpp
        code/Person.h
        code/Integer.cpp
        code/Integer.h
        code/Animal.cpp
        code/Animal.h
        code/Cat.cpp
        code/Cat.h
        code/AbstractCalculator.cpp
        code/AbstractCalculator.h
        code/AbstractCalculator.h
        code/Worker.cpp
        code/Worker.h
        code/WorkManager.cpp
        code/WorkManager.h
        code/Employee.cpp
        code/Employee.h
        code/Manager.cpp
        code/Manager.h
        code/Boss.cpp
        code/Boss.h
        code/S.cpp
        code/S.h
        code/S.hpp
        code/MyArray.hpp
        code/SpeechManager.cpp
        code/SpeechManager.h
        code/Speaker.cpp
        code/Speaker.h
)
