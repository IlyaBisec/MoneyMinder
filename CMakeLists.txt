cmake_minimum_required(VERSION 3.0)

project(MoneyMinder
  VERSION 0.0.1
  LANGUAGES CXX
)

# Turn on C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add toolchain-файл vcpkg
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file"
)

# Find libs from vcpkg manifest
find_package(Sqlite3  REQUIRED)
find_package(wxWidgets CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(matplotplusplus CONFIG REQUIRED)

# Install include and wxWidgets libs
#include(${wxWidgets_USE_FILE})

# Build binary file
add_executable(MoneyMinder
  MoneyMinder/MoneyMinderMain.cpp
)

# Depedency linking
target_link_libraries(MoneyMinder
  PRIVATE
    sqlite3 
    wxWidgets
    spdlog
    matplotplusplus
)
