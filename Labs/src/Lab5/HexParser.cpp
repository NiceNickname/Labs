#include "HexParser.h"
#include <iostream>

std::vector<std::string> HexParser::numbers;

void HexParser::Solve(int argc, char* argv[])
{
	std::cout << "Solving Lab 5: parsing hex numbers" << std::endl;
	if (!ParseArguments(argc, argv))
	{
		return;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << HexToDec(numbers[i]) << " ";
	}
	std::cout << std::endl;
}

int HexParser::HexToDec(const std::string& str)
{
	int power;
	int size = str.length();
	int digit;
	int sum = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		power = size - i - 1;
		sum += pow(16, power) * GetDigit(str[i]);
	}

	return sum;
}

bool HexParser::ParseArguments(int argc, char* argv[])
{
	if (argc != 7)
	{
		std::cout << "Wrong argument count" << std::endl;
		return false;
	}

	std::cout << "Passed parameters: ";
	for (int i = 2; i < 7; i++)
	{
		numbers.push_back(argv[i]);
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	return true;
}

int HexParser::GetDigit(char character)
{
	switch (character)
	{
	case 'a':
		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	default:
		return character - '0';
	}
}
