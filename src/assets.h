#pragma once

#include <boost/filesystem.hpp>
#include <string>


namespace fs = boost::filesystem;

namespace file
{
	/* Returns the game's main directory
	*/
	fs::path getMainDirectory()
	{
		return fs::current_path().parent_path() /= "Chess";
	}

	/* Gets the path relative to the main game directory
	*
	* @param subpath The subpath find. Works with both a path and a string
	*/
	fs::path getMainDirectoryFile(fs::path subpath)
	{
		fs::path path = (fs::current_path().parent_path() /= "Chess") /= subpath;

		return path;
	}

	fs::path getGfxFile(fs::path subpath)
	{
		return getMainDirectoryFile("gfx") /= subpath;
	}

	/* Returns the game's main directory
	*/
	std::string getMainDirectoryStr()
	{
		//looks crazy, I know, but it's necessary because the compiler whines if we don't use a pointer for parent_path()
		fs::path path = fs::current_path().parent_path();
		return path.string();
	}

	/* Gets the path relative to the main game directory
	*
	* @param subpath The subpath find. Works with both a path and a string
	*/
	std::string getMainDirectoryFileStr(fs::path subpath)
	{
		fs::path path = fs::current_path().parent_path() /= subpath;

		return path.string();
	}


}
