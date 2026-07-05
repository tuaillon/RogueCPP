#pragma once

#include <filesystem>
#include <string>
#include <fstream>

#include "Entity/Player.h"

class SaveHandler
{
public:

	static Player fromFile(const std::string& filename);
	static void ToFile(const Player& player);
	static void createSaveDirectory();
	static void displaySaves();

private:
	inline static const std::string m_dirName = "RogueSaves";
	
};
