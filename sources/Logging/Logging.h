#ifndef LOGGING_H__
#define LOGGING_H__

#include <cstdio>
#include <iostream>

#include "spdlog/spdlog.h"

#define LOG_HERE		spdlog::get( "SystemLog" )

void InitializeLogging( void );

#endif
