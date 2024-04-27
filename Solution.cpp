#include "Solution.h"

void Solution::addToSolution(int a) {
	solution.push_back(a);
}
void Solution::addToSolution2(int a) {
	solution2.push_back(a);
}

void Solution::displaySolution() {
	std::cout << "criterion ";
	if (this->criterion == bruteForce) std::cout << "Brute forced" << std::endl;
	if (this->criterion == bruteForce3) std::cout << "Brute forced 3 machine" << std::endl;
	if (this->criterion == LSA) std::cout << "LSA" << std::endl;
	if (this->criterion == LPT) std::cout << "LPT" << std::endl;
	if (this->criterion == PDalg) std::cout << "PD" << std::endl;
	if (this->criterion == PTAS) std::cout << "PTAS" << std::endl;
	if (this->criterion == PTAS3) std::cout << "PTAS 3 machine" << std::endl;
	if (this->criterion == FPTAS) std::cout << "FPTAS" << std::endl;
	if (this->criterion == PDalg3) std::cout << "PD 3 machine" << std::endl;
	if (criterion == bruteForce3 || criterion == PTAS3) {
		std::cout << "solution1: ";
		for (int i = 0; i < solution.size(); i++) {
			std::cout << solution[i] << " ";
		}
		std::cout << "solution2: ";
		for (int i = 0; i < solution2.size(); i++) {
			std::cout << solution2[i] << " ";
		}

	}
	else {
		std::cout << "solution: ";
		for (int i = 0; i < solution.size(); i++) {
			std::cout << solution[i] << " ";
		}

	}
	
	std::cout << "In time: " << this->finish_time;
	std::cout << std::endl;
}