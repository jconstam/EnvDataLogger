#include "Logging.h"

static std::shared_ptr< spdlog::logger > systemLog;

void InitializeLogging( void )
{
	std::vector< spdlog::sink_ptr > sinks;
	sinks.push_back( std::make_shared< spdlog::sinks::stdout_sink_mt >( ) );
	sinks.push_back( std::make_shared< spdlog::sinks::simple_file_sink_mt >( "SystemLogFile", "txt" ) );

	systemLog = std::make_shared< spdlog::logger >( "SystemLog", begin( sinks ), end( sinks ) );

	spdlog::register_logger( systemLog );
}
