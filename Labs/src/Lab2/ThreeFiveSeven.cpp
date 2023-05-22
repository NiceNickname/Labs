#include "ThreeFiveSeven.h"
#include <CmdLineParser/CmdLineParser.h>
#include <iostream>
#include <cmath>

int ThreeFiveSeven::n = 0;

void ThreeFiveSeven::Solve(int argc, char* argv[])
{
	std::cout << "Solving Lab 2: checking numbers for being a power of either 3, 5 or 7" << std::endl;

	if (!ParseArguments(argc, argv))
	{
		return;
	}

	for (int i = 3; i <= n; i++)
	{
		if (IsPower(i, 3) || IsPower(i, 5) || IsPower(i, 7))
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

bool ThreeFiveSeven::ParseArguments(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Too few arguments" << std::endl;
		return false;
	}

	if (!CmdLineParser::ParseInt(argv[2], &n))
	{
		std::cout << "Failed to parse n" << std::endl;
		return false;
	}

	std::cout << "Passed parameters: n=" << n << std::endl;
	return true;
}

bool ThreeFiveSeven::IsPower(int number, int base)
{
	while (number % base == 0) {
		number /= base;
	}
	return number == 1;
}
