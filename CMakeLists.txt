cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

# Add vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "C:/Users/robma/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(sqlite_orm CONFIG REQUIRED)

include_directories("C:/Users/robma/.vcpkg-clion/vcpkg/installed/x64-windows/include")

add_executable(LibraryManagementSystem main.cpp)
target_link_libraries(LibraryManagementSystem PRIVATE sqlite_orm::sqlite_orm)