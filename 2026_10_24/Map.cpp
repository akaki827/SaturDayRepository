#include "Map.h"
#include "Dxlib.h"

#include<fstream>
#include<sstream>
#include<string>

Map::Map() :
	mapXNum(0), mapYNum(0), isInitialized(false)
{
	for (int i = 0; i < Config::MAP_CHIP_IMAGE_COUNT; i++)
	{
		chipImages[i] = -1;
	}
}

Map::~Map() 
{
	Finalize();
}
