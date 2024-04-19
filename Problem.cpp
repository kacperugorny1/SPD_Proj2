#include "Problem.h"


Problem::Problem(int a, int limit) : n(a), Pj(std::vector<int>(n)){
	srand(time(NULL));
	for (int i = 0; i < a; i++) {
		Pj[i] = rand() % limit + 1;
	}
}

Solution Problem::BruteForce_2machine()
{
	int best_time = std::numeric_limits<int>::max(), best_order = 0;
	int time1, time2;
	for (int i = 0; i < powl(2,n)/2; ++i) {
		time1 = 0; time2 = 0;
		for (int j = 0; j < n; ++j) if ((i >> j) & 1) time1 += Pj[j]; else time2 += Pj[j];
		if (std::max(time1, time2) < best_time) { best_time = std::max(time1, time2); best_order = i; }
	}
	Solution sol(bruteForce, best_time);
	for (int i = 0; i < n; ++i) { if ((best_order >> i) & 1) sol.addToSolution(i); }

	return sol;
}

void Problem::displayProblem()
{

	for (int i = 0; i < n; ++i) std::cout << Pj[i] << " ";
	std::cout << std::endl;
}
