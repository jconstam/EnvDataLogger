cmake_minimum_required( VERSION 2.6 )

set( PROJECT_BASE EnvDataLogger )

set( CMAKE_VERBOSE_MAKEFILE OFF )

set( SOURCES ${SOURCES} sources/Decimator/Decimator.cpp )

include_directories( sources/Decimator )

if( CMAKE_BUILD_TYPE MATCHES Release )
	set( PROJ_NAME ${PROJECT_BASE} )

	project( ${PROJ_NAME} )

	set( SOURCES ${SOURCES} sources/Main/Main.cpp )

	add_executable( ${PROJ_NAME} ${SOURCES} )
elseif( CMAKE_BUILD_TYPE MATCHES UnitTests )
	set( PROJ_NAME ${PROJECT_BASE}_UnitTests )
	set( CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0" )

	project( ${PROJ_NAME} )

	set( SOURCES ${SOURCES} tests/Decimator_Tests.cpp )

	add_subdirectory( googletest )
	enable_testing( )
	include_directories( ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
	add_executable( ${PROJ_NAME} ${SOURCES} )
	target_link_libraries( ${PROJ_NAME} gtest gtest_main pthread )
endif( )
