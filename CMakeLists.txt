CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)
PROJECT(palindromecpp CXX)

SET(palindromecpp_VERSION_MAJOR 0)
SET(palindromecpp_VERSION_MINOR 0)
SET(palindromecpp_VERSION_PATCH 2)

SET(WALLAROO_SRC_PATH "$ENV{WALLAROO_LIB}")
SET(SCRIPT_DIR "${PROJECT_SOURCE_DIR}/scrpt")
SET(PROJECT_DIR "${CMAKE_BINARY_DIR}")
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/src")
SET( CMAKE_CXX_LINK_EXECUTABLE "${SCRIPT_DIR}/linker.sh")



MESSAGE(WARN "LOOKING FOR: ${WALLAROO_SRC_PATH}")
IF("${WALLAROO_SRC_PATH}" STREQUAL "" ) 
	 MESSAGE( FATAL_ERROR "WALLAROO_LIB not set correctly!")
ENDIF()


#
# pkg-config suppor
#
find_package(PkgConfig REQUIRED)


# cxx 11
#
INCLUDE(CheckCXXCompilerFlag)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
IF (COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(CMAKE_CXX_STANDARD 11)
ENDIF ()



#
# 32/64 bits
#
IF("${CMAKE_SIZEOF_VOID_P}" EQUAL "8") 
  MESSAGE(STATUS "64 BIT System detected")
  SET(CMAKE_CXX_FLAGS -m64)
  SET(CMAKE_C_FLAGS -m64)
ELSE("${CMAKE_SIZEOF_VOID_P}" EQUAL "8") 
  MESSAGE(STATUS "32 BIT System detected")
  SET(CMAKE_CXX_FLAGS -m32)
  SET(CMAKE_C_FLAGS -m32)
ENDIF("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")



#
# additional c++
#
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
FIND_PACKAGE(Threads REQUIRED)
message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")


#
# ponyc & wallaroo
#
pkg_check_modules(PONYC REQUIRED ponyc)
pkg_check_modules(WLRCPPAAPI REQUIRED wallaroocppapi)


#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#  message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()




# c++ files
set (
  SOURCE_FILES
  src/PalindromeIO.hpp
  src/PalindromeIO.cpp
  src/Palindrome.cpp
  src/Palindrome.hpp
  src/main.cpp
  )


	
#
# the pony stuff
#
message(STATUS "Current souce dir: ${CMAKE_CURRENT_SOURCE_DIR}/src")
add_custom_command(OUTPUT ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/src.o
  COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR} && ponyc --debug --pic --pass=obj --path=${WALLAROO_SRC_PATH} --output=${CMAKE_LIBRARY_OUTPUT_DIRECTORY} ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_library(
  bootstrap
  STATIC
  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/src.o)
SET_SOURCE_FILES_PROPERTIES(
  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/src.o
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true)
SET_TARGET_PROPERTIES(
  bootstrap
  PROPERTIES
  LINKER_LANGUAGE CXX)
SET (bootstrap -Wl,--whole-archive ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/src.o -Wl,--no-whole-archive)




message(STATUS "pony and wallaroo libs: ${PONYC_LIBRARIES};${WLRCPPAAPI_LIBRARIES}")
message(STATUS "\tfrom: ${SEND_PONY_STATIC_LIBRARY_DIRS}")
message(STATUS "\tfrom: ${WLRCPPAAPI_STATIC_LIBRARY_DIRS}")
message(STATUS "\tfrom: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

add_executable(palindrome ${SOURCE_FILES})
target_link_libraries(palindrome ${PYTHON_LIBRARIES} Threads::Threads)
target_link_libraries(palindrome bootstrap)
