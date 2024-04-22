#pragma once


#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>
#include "Solution.h"
class Problem
{
	int n;

	std::vector<int> Pj;

public:
	Problem(int a, int limit);

	Solution BruteForce_2machine();

	Solution LSAAlgorithm();

	Solution LPTAlgorithm();

	void displayProblem();
};

