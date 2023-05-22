#include "Spiral.h"
#include <iostream>
#include <stdio.h>
#include <CmdLineParser/CmdLineParser.h>

int Spiral::n = 0;
std::vector<int> Spiral::result;

void Spiral::Solve(int argc, char* argv[])
{
	std::cout << "Solving Lab 4: filling a matrix in a spiral order" << std::endl;
	if (!ParseArguments(argc, argv))
	{
		return;
	}

	FillSpiral();
	PrintResult();
}

bool Spiral::ParseArguments(int argc, char* argv[])
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
	result.resize(n * n);
	return true;
}

void Spiral::FillSpiral()
{
	std::vector<std::vector<bool> > seen(n, std::vector<bool>(n, false));
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };

	int x = 0, y = 0, di = 0;

	for (int i = 0; i < n * n; i++) {
		result[x * n + y] = i + 1;
		seen[x][y] = true;
		int newX = x + dr[di];
		int newY = y + dc[di];

		if (0 <= newX && newX < n && 0 <= newY && newY < n
			&& !seen[newX][newY]) {
			x = newX;
			y = newY;
		}
		else {
			di = (di + 1) % 4;
			x += dr[di];
			y += dc[di];
		}
	}
}

void Spiral::PrintResult()
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
			printf("%5d ", result[i * n + j]);
	}
	printf("\n");
}
