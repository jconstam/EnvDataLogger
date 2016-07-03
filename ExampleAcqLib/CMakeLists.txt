cmake_minimum_required( VERSION 2.6 )

set( PROJECT_NAME ExampleAcqLib )

project( ${PROJECT_NAME} )

set( CMAKE_VERBOSE_MAKEFILE OFF )

include_directories( src )
set( SOURCES ${SOURCES} src/ExampleAcqLib.cpp )

add_library( ${PROJECT_NAME} SHARED ${SOURCES} )