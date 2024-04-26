#include "Solution.h"

void Solution::addToSolution(int a) {
	solution.push_back(a);
}

void Solution::addTimeToSoultion(int a) {
	solution_times.push_back(a);
}

void Solution::displaySolution() {
	std::cout << "criterion ";
	if (this->criterion == bruteForce) std::cout << "Brute forced" << std::endl;
	if (this->criterion == LSA) std::cout << "LSA" << std::endl;
	if (this->criterion == LPT) std::cout << "LPT" << std::endl;
	if (this->criterion == PDalg) std::cout << "PD" << std::endl;
	std::cout << "solution: ";
	for (int i = 0; i < solution.size(); i++) {
		std::cout << solution[i] << " ";
	}
	std::cout << "In time: " << this->finish_time;
	std::cout << std::endl;
}