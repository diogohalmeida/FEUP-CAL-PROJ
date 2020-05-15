cmake_minimum_required(VERSION 3.15)
project(ExploreIT)

set(CMAKE_CXX_STANDARD 14)
# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
link_libraries(ws2_32 wsock32)

include_directories(lib)
include_directories(resources)
add_executable(ExploreIT main.cpp lib/connection.cpp lib/graphviewer.cpp src/Utils/readFileGraph.cpp src/Utils/readFileGraph.h src/Graph/Graph.h src/Graph/Graph.cpp src/Utils/utils.cpp src/Utils/utils.h src/Interface/menu.cpp src/Interface/menu.h src/Interface/GraphDisplay.cpp src/Interface/GraphDisplay.h src/Utils/verifications.cpp src/Utils/verifications.h)
