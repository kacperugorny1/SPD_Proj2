#pragma once

#include <vector>
#include <iostream>

typedef enum {
	bruteForce,
	LSA,
	LPT,
	PDalg
} SolutionType;

class Solution
{
	std::vector<int> solution; // indexy
	SolutionType criterion; // wykorzystane kryterium
	int finish_time; //Czas
	std::vector<int> solution_times; //czasy wykonywania dla kolejnych wyników

public:

	Solution(SolutionType crit, int time) { criterion = crit; finish_time = time; }

	~Solution() {};

	void addToSolution(int a);

	int getFinishTime() { return finish_time; };

	std::vector<int> getSolution() { return solution; };

	void addTimeToSoultion(int index);

	void displaySolution();
};

