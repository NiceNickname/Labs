#include "CmdLineParser.h"
#include <stdio.h>

bool CmdLineParser::ParseInt(char* str, int* result)
{
	if (sscanf(str, "%d", result) != 1)
	{
		return false;
	}
	return true;
}

bool CmdLineParser::ParseDouble(char* str, double* result)
{
	if (sscanf(str, "%lf", result) != 1)
	{
		return false;
	}
	return true;
}

