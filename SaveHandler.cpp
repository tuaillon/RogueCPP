#include "SaveHandler.h"
using namespace std::filesystem;

Player SaveHandler::fromFile(const std::string& filename)
{
	return Player();
}

void SaveHandler::ToFile(const Player& player)
{
}

void SaveHandler::createSaveDirectory()
{
	if ( !exists(m_dirName) )
		create_directory(m_dirName);
}

void SaveHandler::displaySaves()
{
	for ( const auto& entry : directory_iterator(m_dirName) )
	{
		std::cout << entry.path().filename() << "\n";
	}
}
