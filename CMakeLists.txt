cmake_minimum_required(VERSION 3.0.0)
project(DB_Reader VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(PostgreSQL_INCLUDE_DIRS "/usr/lib/postgresql" )

set(PostgreSQL_ADDITIONAL_VERSIONS "14")
find_package(PostgreSQL REQUIRED)

add_executable(DB_Reader main.cpp)
add_subdirectory(libraries/libpqxx build-pqxx)

target_link_libraries(DB_Reader PRIVATE pqxx)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

