#pragma once

class CmdLineParser
{
public:
	static bool ParseInt(char* str, int* result);
	static bool ParseDouble(char* str, double* result);
};