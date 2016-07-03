#include "ExampleAcqLib.h"

class ExAcqLib
{
	public:
		static string Name( )
		{
			return "Example Acquisition Library";
		}
};

static ExAcqLib acqLib;

string GetName( void )
{
	return acqLib.Name( );
}
