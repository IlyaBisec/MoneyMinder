
include(CMakeFindDependencyMacro)
if(NOT WIN32)
    find_dependency(Threads)
endif()
if("dynamic" STREQUAL "static")
    find_package(ICU COMPONENTS uc i18n)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/unofficial-sqlite3-targets.cmake)
