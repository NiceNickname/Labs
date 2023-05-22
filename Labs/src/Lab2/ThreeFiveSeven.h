#pragma once


class ThreeFiveSeven
{
public:
	static void Solve(int argc, char* argv[]);
private:
	static bool ParseArguments(int argc, char* argv[]);
	static bool IsPower(int number, int base);

private:
	static int n;
};