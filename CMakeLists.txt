cmake_minimum_required( VERSION 2.6 )

set( PROJECT_BASE EnvDataLogger )
set( RELEASE_PROJ ${PROJECT_BASE} )
set( UNITTEST_PROJ ${PROJECT_BASE}_UnitTests )

project( ${RELEASE_PROJ} )
project( ${UNITTEST_PROJ} )

set( CMAKE_VERBOSE_MAKEFILE OFF )

set( CMAKE_CXX_FLAGS "-std=c++11" )
	
set( SOURCES ${SOURCES} sources/Decimator/Decimator.cpp )

include_directories( sources/Decimator )
include_directories( sources/spdlog/include )

if( CMAKE_BUILD_TYPE MATCHES Release )
	set( SOURCES ${SOURCES} sources/Main/Main.cpp )

	add_executable( ${RELEASE_PROJ} ${SOURCES} )
	target_link_libraries( ${RELEASE_PROJ} czmq zmq protobuf pthread )
elseif( CMAKE_BUILD_TYPE MATCHES UnitTests )
	set( CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -fPIC -O0" )

	set( SOURCES ${SOURCES} tests/Decimator_Tests.cpp )

	add_subdirectory( googletest )
	enable_testing( )
	include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
	
	add_executable( ${UNITTEST_PROJ} ${SOURCES} )
	target_link_libraries( ${UNITTEST_PROJ} gtest gtest_main pthread )
endif( )
