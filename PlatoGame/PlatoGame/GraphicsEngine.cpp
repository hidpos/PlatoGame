#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	D3D10_DRIVER_TYPE driver_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,

	};
	D3D11CreateDevice(NULL, );
	return true;
}

bool GraphicsEngine::release()
{
	return true;
}

GraphicsEngine::~GraphicsEngine()
{
}
