#pragma once

#include <vector>
#include <iostream>

typedef enum {
	bruteForce,
	LSA,
	LPT,
	PDalg,
	PTAS,
	FPTAS,
	bruteForce3,
	PTAS3,
	PDalg3
} SolutionType;

class Solution
{
	std::vector<int> solution; // indexy
	std::vector<int> solution2;
	SolutionType criterion; // wykorzystane kryterium
	int finish_time; //Czas

public:

	Solution(SolutionType crit, int time) : criterion(crit), finish_time(time) { };
	Solution() {};

	~Solution() {};

	void addToSolution(int a);
	void addToSolution2(int a);

	int getFinishTime() { return finish_time; };
	void setFinishTime(int a) { finish_time = a; };
	void setCriterion(SolutionType crit) { criterion = crit; };


	std::vector<int> getSolution() { return solution; };
	std::vector<int> getSolution2() { return solution2; };


	void displaySolution();
};

