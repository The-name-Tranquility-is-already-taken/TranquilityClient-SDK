cmake_minimum_required(VERSION 3.21)
project(TranquilitySDK)

include_directories(
        ./include
        ./Curl-7.76.0/curl
        ./json/include/
)

set(CMAKE_CXX_STANDARD 17)

add_library(TranquilitySDK SHARED
        src/client.cpp
        include/client.hpp

        src/networking.cpp
        include/networking.hpp

        src/auth.cpp
        include/auth.h

        include/includes.h
        include/errors.h


        src/user.cpp include/core/user.h include/base_object.h src/cache.cpp include/cache.h src/guild.cpp include/core/guild.h include/core/channels.cpp include/core/channels.h)
find_package(CURL REQUIRED)

include(FetchContent)

FetchContent_Declare(json
        URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
        )

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(TranquilitySDK_Test ./test/main.cpp)
target_link_libraries(TranquilitySDK_Test PRIVATE TranquilitySDK curl nlohmann_json::nlohmann_json)
