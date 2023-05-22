#pragma once
#include <vector>

class PositiveNegative
{
public:
	static void Solve(int argc, char* argv[]);
private:
	static bool ParseArguments(int argc, char* argv[]);
private:
	static std::vector<int> numbers;
};