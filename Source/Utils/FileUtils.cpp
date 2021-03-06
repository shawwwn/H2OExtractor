/* FileUtils.cpp */
#include "FileUtils.h"

namespace Util { namespace File {
	
	// Is the provided path a folder or a file
	PathType checkPathType(const char* dirPath)
	{
		if (access(dirPath, 0)==0)
		{
			struct stat status;
			stat(dirPath, &status);
			if ( status.st_mode & S_IFDIR )
				return TYPE_DIR;
			else
				return TYPE_FILE;
		}
		return TYPE_NOT_EXIST;
	}

}}