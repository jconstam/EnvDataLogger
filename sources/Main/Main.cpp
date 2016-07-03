#include <cstdlib>
#include <dlfcn.h>

#include "ExampleAcqLib.h"

#include "Logging.h"

using namespace std;

int main( int argc, char* argv[ ] )
{
	void* libHandle;
	string ( *GetNameFunc )( void );

	InitializeLogging( );

	LOG_HERE->info( "EnvDataLogger Starting Up" );

	libHandle = dlopen( "bin/Release/acqlibs/libExampleAcqLib.so", RTLD_LAZY);
	if( libHandle == nullptr )
	{
		LOG_HERE->emerg( "Couldn't open shared library" );
	}
	else
	{
		GetNameFunc = ( string ( * )( void ) ) dlsym( libHandle, "GetName" );
		if( GetNameFunc == nullptr )
		{
			LOG_HERE->emerg( "Couldn't get function pointer" );
		}
		else
		{
			LOG_HERE->alert( "Library name: {}", ( *GetNameFunc )( ) );
		}
	}

	LOG_HERE->info( "EnvDataLogger Shutting Down" );

	return 0;
}
