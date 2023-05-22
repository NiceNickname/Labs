#pragma once

struct Args
{
	double distance;
	double acceleration;
};


class VelocityCalculator
{
public: 
	static void Solve(int argc, char* argv[]);
private:
	static double Calculate(double distance, double acceleration);
	static bool ParseArguments(int argc, char* argv[]);

private:
	static Args args;
};