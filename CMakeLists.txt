cmake_minimum_required(VERSION 3.25)
project(LAB9OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(LAB9OOP main.cpp Tests.cpp Tests.h Movie.cpp Movie.h Exceptions.cpp Exceptions.h Validator.cpp Validator.h MovieRepository.cpp MovieRepository.h MovieRepositoryFile.cpp MovieRepositoryFile.h Service.cpp Service.h)
