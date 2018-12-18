#
#cmake_minimum_required(VERSION 3.12)
#project(untitled2)

#set(CMAKE_CXX_STANDARD 17)


#FIND_PACKAGE( Boost 1.65.1 COMPONENTS program_options REQUIRED )
#INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})


#add_executable(untitled4 main.cpp proc.h memory.h server.h dcmprssDat.h)

#TARGET_LINK_LIBRARIES( untitled4 LINK_PUBLIC ${Boost_LIBRARIES} )

#cmake_minimum_required(VERSION 3.12)
#project(untitled2)

#set(CMAKE_CXX_STANDARD 17)
#set(Boost_USE_STATIC_LIBS   ON)

#set(Boost_INCLUDE_DIR /usr/local/src/boost_1_65_1)
#set(Boost_LIBRARY_DIR /usr/local/src/boost_1_65_1/stage/lib)
#find_package(Boost COMPONENTS system filesystem REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#link_directories(${Boost_LIBRARY_DIR})

#add_executable(untitled4 main.cpp)
#target_link_libraries(untitled4 ${Boost_LIBRARIES} )


cmake_minimum_required (VERSION 3.12)
project(untitled2)
#set(PROJECT untitled2)
set(CMAKE_CXX_STANDARD 17)
#set(HEADERS dcmprssDat.h, proc.h, memory.h, server.h)

#set(SOURCES main.cpp)

#set(Boost_USE_STATIC_LIBS ON)
#set(BOOST_COMPONENTS iostreams )
#set(Boost_USE_MULTITHREADED ON)
#set(LIBRARIES boost)

find_package(Boost 1.65.1 COMPONENTS program_options filesystem system iostreams)

#if(Boost_FOUND)
#   include_directories(${Boost_INCLUDE_DIRS})
   add_executable(untitled4 main.cpp ${SOURCE_FILES})
   #link_libraries(dcmprssDat.h, proc.h, memory.h, server.h, boost/iostreams)
   #target_link_libraries (untitled2 ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
   target_link_libraries(untitled4 ${Boost_LIBRARIES})#, dcmprssDat.h, proc.h, memory.h, server.h)
#endif()



