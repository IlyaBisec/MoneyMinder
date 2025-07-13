cmake_minimum_required(VERSION 3.21)

project(MoneyMinder
  VERSION 0.0.1
  LANGUAGES CXX
)

# Включаем C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем toolchain-файл vcpkg
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file"
)

# Находит библиотеки из манифеста vcpkg
find_package(SQLite3 CONFIG REQUIRED)
find_package(wxWidgets CONFIG REQUIRED COMPONENTS core base)
find_package(spdlog CONFIG REQUIRED)
find_package(matplotplusplus CONFIG REQUIRED)

# Устанавливаем include и библиотеки wxWidgets
include(${wxWidgets_USE_FILE})

# Собираем исполняемый файл
add_executable(MoneyMinder
  MoneyMinder/MoneyMinderMain.cpp
)

# Линкуем зависимости
target_link_libraries(MoneyMinder
  PRIVATE
    SQLite::SQLite3
    ${wxWidgets_LIBRARIES}
    spdlog::spdlog
    matplotplusplus
)
