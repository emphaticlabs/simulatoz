#include "../include/oz440_api/ApiWatchdogPacket.hpp"
#include "../include/oz440_api/CLByteConversion.h"

//=============================================================================
//
ApiWatchdogPacket::ApiWatchdogPacket( )
{

}

//=============================================================================
//
ApiWatchdogPacket::ApiWatchdogPacket( uint8_t fooValue_ )
	: 	fooValue{ fooValue_ }
{

}

//=============================================================================
//
ApiWatchdogPacket::~ApiWatchdogPacket( )
{

}

//=============================================================================
//
cl::BufferUPtr ApiWatchdogPacket::encode()
{
	uint cpt = 0;

	cl::BufferUPtr buffer = cl::unique_buffer( static_cast<size_t>( 1 ) );

	(*buffer)[cpt++] = static_cast<uint8_t>( fooValue );

	return std::move( getPreparedBuffer( std::move( buffer ), getPacketId() ) );
}

//=============================================================================
//
void ApiWatchdogPacket::decode( uint8_t *buffer, uint bufferSize )
{
	ignore( bufferSize );

	uint cpt = getStartPayloadIndex();

	fooValue = static_cast< uint8_t >( buffer[ cpt++ ] );
}
