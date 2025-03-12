cmake_minimum_required(VERSION 3.8)
project(nmp25)

enable_testing()
set(CMAKE_CXX_STANDARD 11)  # Set to 11, 14, 17, or later
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -lpthread)
endif()

foreach(IDX RANGE 1 3 1)
	add_executable(Question-${IDX}-out Question-${IDX}/Question-${IDX}.cc)
	target_link_libraries(Question-${IDX}-out pthread)
	add_test(question-${IDX} Question-${IDX}-out)
endforeach()


# Question 4: Extension Task. You need to integrate Google Tests here
# Ensure the source file exists
set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/Question-4/Question-4.cc")
if(NOT EXISTS ${SOURCE_FILE})
    message(FATAL_ERROR "Error: ${SOURCE_FILE} not found! Ensure it exists in the correct directory.")
endif()

# ✅ Use FetchContent to download GoogleTest & GoogleMock
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# ✅ Add include directories for GTest & GMock
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# ✅ Define test executable
add_executable(Question-4-out ${SOURCE_FILE})

# ✅ Link against both GoogleTest & GoogleMock
target_link_libraries(Question-4-out GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main pthread)

# ✅ Register the test
add_test(NAME Question-4-Test COMMAND Question-4-out)