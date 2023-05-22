#include <CmdLineParser/CmdLineParser.h>
#include "VelocityCalculator.h"
#include <iostream>

Args VelocityCalculator::args = { 0.0, 0.0 };

void VelocityCalculator::Solve(int argc, char* argv[])
{
	std::cout << "Solving Lab 1: calculating train's velocity" << std::endl;
	if (!ParseArguments(argc, argv))
	{
		return;
	}
	std::cout << "The velocity equals: " << Calculate(args.distance, args.acceleration) << std::endl;
}

double VelocityCalculator::Calculate(double distance, double acceleration)
{
	double time = sqrt(distance * 2 / acceleration);
	double result = time * acceleration;
	return result;
}

bool VelocityCalculator::ParseArguments(int argc, char* argv[])
{
	if (argc < 4)
	{
		std::cout << "Too few arguments" << std::endl;
		return false;
	}

	if (!CmdLineParser::ParseDouble(argv[2], &args.distance))
	{
		std::cout << "Failed to parse distance" << std::endl;
		return false;
	}

	if (!CmdLineParser::ParseDouble(argv[3], &args.acceleration))
	{
		std::cout << "Failed to parse acceleration" << std::endl;
		return false;
	}

	if (args.acceleration <= 0)
	{
		std::cout << "Acceleration cannot be less or equal than 0" << std::endl;
		return false;
	}

	if (args.distance <= 0)
	{
		std::cout << "Traversed distance cannot be less or equal than 0" << std::endl;
		return false;
	}


	std::cout << "Passed parameters: distance=" << args.distance << " acceleration=" << args.acceleration << std::endl;
	return true;
}

