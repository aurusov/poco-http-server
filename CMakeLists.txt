cmake_minimum_required(VERSION 2.5)

project(poco-http-server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(poco-http-server
    src/handlers/Factory.cpp
    src/handlers/Ping.cpp
    src/main.cpp
    src/Server.cpp
)

find_package(Poco REQUIRED Foundation Util Net XML JSON)

target_link_libraries(poco-http-server
    PocoUtil
    PocoNet
    PocoXML
    PocoFoundation
    PocoJSON
    ${CMAKE_THREAD_LIBS_INIT}
)
