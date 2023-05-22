#include "Lab1/VelocityCalculator.h"
#include "Lab2/ThreeFiveSeven.h"
#include "Lab3/PositiveNegative.h"
#include "Lab4/Spiral.h"
#include "Lab5/HexParser.h"
#include "Common/CmdLineParser/CmdLineParser.h"
#include <stdio.h>
#include <cassert>


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Too few command line arguments\n");
		return 1;
	}

	int LabNumber;
	if (!CmdLineParser::ParseInt(argv[1], &LabNumber))
	{
		printf("Could not parse the lab number\n");
		return 2;
	}

	switch (LabNumber)
	{
	case 1:
		VelocityCalculator::Solve(argc, argv);
		break;
	case 2:
		ThreeFiveSeven::Solve(argc, argv);
		break;
	case 3:
		PositiveNegative::Solve(argc, argv);
		break;
	case 4:
		Spiral::Solve(argc, argv);
		break;
	case 5:
		HexParser::Solve(argc, argv);
		break;
	default:
		assert(false, "The lab number is supposed to be equal either 1, 2, 3, 4 or 5");
	}

	return 0;
}