cmake_minimum_required(VERSION 3.10)

# set the project name
project(Street)

# add the executable
add_executable(jabu 
    main.cpp
    Verhalten.cpp
    Fahrzeug.cpp
    SimulationsObjekt.cpp
    Parken.cpp
    PKW.cpp)

link_directories(${CMAKE_SOURCE_DIR}/GUI)

target_link_libraries(jabu
    SimuClient)