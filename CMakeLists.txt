cmake_minimum_required(VERSION 3.5)

project(tamrin2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tamrin2 main.cpp
    shape.h shape.cpp
    square.h square.cpp
    rectangle.h rectangle.cpp
    circle.h circle.cpp)

include(GNUInstallDirs)
install(TARGETS tamrin2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
