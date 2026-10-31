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
//
bool Map::LoadMap(const char* filePath, std::vector<std::vector<int>>& mapData)
{
	std::ifstream file(filePath);

	//ファイルが開かなかった場合
	if (!file.is_open())
	{
		return false;
	}
	mapData.clear();

	std::string line;

	//ファイルから文字列を１行ずつ取ってくる
	while (std::getline(file, line))
	{
		//文字列がなかったら
		if (line.empty())
		{
			continue;
		}
		std::vector<int>row;
		std::stringstream lineStream(line);
		std::string cell;

		while (std::getline(lineStream, cell))
		{
			std::stringstream cellStream(cell);
			int value = Config::MAP_EMPTY;

			if (!(cellStream >> value))
			{
				return false;
			}

			row.push_back(value);
		}
		if (row.empty())
		{
			return false;
		}
		//CSVの各行の横幅が同じことであることを確認する
		if (!mapData.empty() && row.size() != mapData[0].size())
		{
			return false;
			mapData.push_back(row);
		}

	}

	return !mapData.empty();
}
//描画
void Map::Draw() const
{
	if (!isInitialized)
	{
		return;
	}
	// 描画順：奥の背景 → 地面 → 手前    DrawLayer(backMap);
	DrawLayer(baseMap);
	DrawLayer(nearMap);
}
//描画レイヤー
void Map::DrawLayer(const std::vector<std::vector<int>>& mapData) const
{
	for (int y = 0; y < static_cast<int>(mapData[y].size()); ++y)
	{
		for (int x = 0; x < static_cast<int>(mapData[x].size()); ++x)
		{
			const int chipNumber = mapData[y][x];
			if (chipNumber == Config::MAP_EMPTY)
			{
				continue;
			}
			//CSVのチップ番号は1から始まり、画像配列の番号は0始まり
			const int chipIndex = chipNumber - 1;
			if (chipIndex < 0 || chipIndex >= Config::MAP_CHIP_IMAGE_COUNT)
			{
				continue;
			}
			const int drawX = Config::MAP_DRAW_ORIGIN_X + x * Config::MAP_CHIP_SIZE;
			const int drawY = Config::MAP_DRAW_ORIGIN_Y + y * Config::MAP_CHIP_SIZE;
			DrawGraph(drawX, drawY, chipImages[chipIndex], TRUE);
		}
	}
}
//描画フラグ
bool Map::IsValidMapPosition(int mapX, int mapY) const
{
	if (mapX < 0 || mapY < 0)
	{
		return false;
	}

	return true;
}
//終了処理
void Map::Finalize()
{
	for (int i = 0; i < Config::MAP_CHIP_IMAGE_COUNT; ++i)
	{
		if (chipImages[i] != -1)
		{
			DeleteGraph(chipImages[i]);
			chipImages[i] = -1;
		}
	}

	backMap.clear();
	baseMap.clear();
	nearMap.clear();

	mapXNum = 0;
	mapYNum = 0;
	isInitialized = false;
}