add_library(libtasiadb src/parser.cpp)

target_include_directories(libtasiadb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
