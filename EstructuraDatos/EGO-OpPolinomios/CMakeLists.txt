cmake_minimum_required(VERSION 3.9)
project(EGO_OpPolinomios)

set(CMAKE_CXX_STANDARD 98)

add_executable(EGO_OpPolinomios main.cpp Racional.cpp Racional.h Excepcion.h Monomio.cpp Monomio.h CapturaDato.h Polinomio.cpp Polinomio.h)