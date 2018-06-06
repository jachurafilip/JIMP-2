
project(arabictoroman)

set(HEDEAR_FILES ArabicToRoman.h)
set(SOURCE_FILES ArabicToRoman.cpp)

add_library(libarabicroman STATIC ${SOURCE_FILES})
target_include_directories(libarabicroman PUBLIC .)

add_executable(arabictoroman ${SOURCE_FILES} main.cpp)

target_link_libraries(arabictoroman libarabicroman)

