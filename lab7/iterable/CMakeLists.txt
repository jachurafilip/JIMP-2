
project(iterable)

set(HEDEAR_FILES IterableIterators.h IterableIteratorWrapper.h Iterable.h)
set(SOURCE_FILES IterableIterators.cpp IterableIteratorWrapper.cpp Iterable.cpp)

add_library(libiterable STATIC ${SOURCE_FILES})
target_include_directories(libiterable PUBLIC .)

add_executable(iterable ${SOURCE_FILES} main.cpp)

target_link_libraries(iterable libiterable)

