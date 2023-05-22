#pragma once
#include <vector>
#include <string>

class HexParser
{
public:
	static void Solve(int argc, char* argv[]);
	
private:
	static int  HexToDec(const std::string& str);
	static bool ParseArguments(int argc, char* argv[]);
	static int GetDigit(char character);

private:
	static std::vector<std::string> numbers;
};