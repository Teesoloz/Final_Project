cmake_minimum_required(VERSION 3.21)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Final_Project main.cpp Player.cpp Player.h Enemy.cpp Enemy.h Bullet.cpp Bullet.h)
target_link_libraries(Final_Project sfml-graphics sfml-audio)
