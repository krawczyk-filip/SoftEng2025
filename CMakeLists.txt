cmake_minimum_required(VERSION 3.10)
project(SortLib)

set(CMAKE_CXX_STANDARD        17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MDd")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

set(SOURCES
	src/Bubble.cpp
	src/Insert.cpp
	src/Merge.cpp
	src/OpState.cpp
	src/Quick.cpp
	src/Radix.cpp
	src/Select.cpp
	src/SortData.cpp
	src/SortDataBase.cpp
	src/Sorter.cpp
	src/SortError.cpp
	src/SortSeparateData.cpp
	src/SortTech.cpp
	src/SortTechFactory.cpp
)

set(HEADERS
	src/Bubble.h
	src/Insert.h
	src/Merge.h
	src/OpState.h
	src/Quick.h
	src/Radix.h
	src/Select.h
	src/SortData.h
	src/SortDataBase.h
	src/Sorter.h
	src/SortError.h
	src/SortSeparateData.h
	src/SortTech.h
	src/SortTechFactory.h
)



add_library(SortLib SHARED ${SOURCES} ${HEADERS})

#target_link_libraries(SortLib PUBLIC Lib::Lib)

target_compile_definitions(SortLib PRIVATE BUILDING_CLIENT_DLL)




enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(externals/googletest)

add_executable(test_sort1 src/tests/test_sort1.cpp)
target_link_libraries(test_sort1 gtest gtest_main SortLib)
target_include_directories(test_sort1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_sort2 src/tests/test_sort2.cpp)
target_link_libraries(test_sort2 gtest gtest_main SortLib)
target_include_directories(test_sort2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_radix src/tests/test_radix.cpp)
target_link_libraries(test_radix gtest gtest_main SortLib)
target_include_directories(test_radix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_merge src/tests/test_merge.cpp)
target_link_libraries(test_merge gtest gtest_main SortLib)
target_include_directories(test_merge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_select src/tests/test_select.cpp)
target_link_libraries(test_select gtest gtest_main SortLib)
target_include_directories(test_select PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_bubble src/tests/test_bubble.cpp)
target_link_libraries(test_bubble gtest gtest_main SortLib)
target_include_directories(test_bubble PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_quick src/tests/test_quick.cpp)
target_link_libraries(test_quick gtest gtest_main SortLib)
target_include_directories(test_quick PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_executable(test_insert src/tests/test_insert.cpp)
target_link_libraries(test_insert gtest gtest_main SortLib)
target_include_directories(test_insert PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src  PRIVATE ${PROJECT_BINARY_DIR})

add_test(NAME test_sort1 COMMAND test_sort1)
add_test(NAME test_sort2 COMMAND test_sort2)
add_test(NAME test_insert COMMAND test_insert)
add_test(NAME test_radix COMMAND test_radix)
add_test(NAME test_merge COMMAND test_merge)
add_test(NAME test_select COMMAND test_select)
add_test(NAME test_bubble COMMAND test_bubble)
add_test(NAME test_quick COMMAND test_quick)