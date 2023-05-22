#pragma once
#include <vector>

class Spiral
{
public:
	static void Solve(int argc, char* argv[]);
private:
	static bool ParseArguments(int argc, char* argv[]);
	static void FillSpiral();
	static void PrintResult();

private:
	static int n;
	static std::vector<int> result;
};