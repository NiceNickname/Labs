#include "PositiveNegative.h"
#include <CmdLineParser/CmdLineParser.h>
#include <iostream>

std::vector<int> PositiveNegative::numbers;

void PositiveNegative::Solve(int argc, char* argv[])
{
	std::cout << "Solving Lab 3: counting positives and negatives inside an array" << std::endl;
	if (!ParseArguments(argc, argv))
	{
		return;
	}
	int positiveCount = 0, negativeCount = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > 0)
		{
			positiveCount++;
		}
		else
		{
			negativeCount++;
		}
	}

	std::cout << "Positive numbers: " << positiveCount << " NegativeNumbers: " << negativeCount << std::endl;
}

bool PositiveNegative::ParseArguments(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Too few arguments" << std::endl;
		return false;
	}
	int arraySize;
	if (!CmdLineParser::ParseInt(argv[2], &arraySize))
	{
		std::cout << "Failed to parse array size" << std::endl;
		return false;
	}

	if (arraySize < 1)
	{
		std::cout << "Size of the array cannot be less than 1" << std::endl;
		return false;
	}

	std::cout << "Passed parameters: array size=" << arraySize << std::endl;
	std::cout << "Array = { ";
	numbers.resize(arraySize);
	srand((unsigned)time(NULL));
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = (rand() % 200) - 100;
		std::cout << numbers[i] << " ";
	}
	std::cout << " }" << std::endl;
	return true;
}