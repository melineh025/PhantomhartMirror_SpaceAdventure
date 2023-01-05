CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test 
tests/unit_test.cpp
src/Map/Tile.cpp
src/Map/Map.cpp
src/Quest/Quest.cpp
src/Quest/Questlog.cpp
)
ADD_EXECUTABLE(Phantomheart 
src/main.cpp 
src/Map/Tile.cpp
src/Map/Map.cpp
src/Quest/Quest.cpp
src/Quest/Questlog.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
