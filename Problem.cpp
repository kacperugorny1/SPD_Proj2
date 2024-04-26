#include "Problem.h"

struct {
	bool operator()(std::pair<int, int> a, std::pair<int, int> b) { return a.first > b.first; }
} customOperator1;


Problem::Problem(int a, int limit) : n(a), Pj(std::vector<int>(n)){
	srand(time(NULL));
	for (int i = 0; i < a; i++) {
		Pj[i] = rand() % limit + 1;
	}
}

Solution Problem::BruteForce_2machine()
{
	int best_time = std::numeric_limits<int>::max();
	int64_t best_order = 0;
	int time1, time2;
	for (int64_t i = 0; i < powl(2,n)/2; ++i) {
		time1 = 0; time2 = 0;
		for (int j = 0; j < n; ++j) if ((i >> j) & 1) time1 += Pj[j]; else time2 += Pj[j];
		if (std::max(time1, time2) < best_time) { best_time = std::max(time1, time2); best_order = i; }
	}
	Solution sol(bruteForce, best_time);
	for (int i = 0; i < n; ++i) { if ((best_order >> i) & 1) sol.addToSolution(i); }

	return sol;
}

Solution Problem::LSAAlgorithm() {
	int best_time;
	int time1 = 0;
	int time2 = 0;
	std::vector<int> tasks;

	for (int i = 0; i < n; i++) {
		if (time1 <= time2) {
			time1 += Pj[i]; tasks.push_back(i);
		}
		else {
			time2 += Pj[i];
		}
	}
	if (time1 >= time2) best_time = time1;
	else best_time = time2;

	Solution sol(LSA, best_time);
	for (int i = 0; i < tasks.size(); i++) sol.addToSolution(tasks[i]);

	return sol;
}

Solution Problem::LPTAlgorithm() {
	int best_time;
	int time1 = 0;
	int time2 = 0;
	std::vector<std::pair<int, int>> sortedTasks;
	std::vector<std::pair<int, int>> tasks;

	for (int i = 0; i < n; i++) sortedTasks.push_back({ Pj[i], i });

	std::sort(sortedTasks.begin(), sortedTasks.end(), customOperator1);

	//for (int i = 0; i < n; i++) std::cout << sortedTasks[i].first << " " << sortedTasks[i].second << std::endl; //Sprawdzenie jest git

	for (int i = 0; i < n; i++) {
		if (time1 <= time2) {
			time1 += sortedTasks[i].first; tasks.push_back({ sortedTasks[i].first, sortedTasks[i].second });
		}
		else {
			time2 += sortedTasks[i].first;
		}
	}
	if (time1 >= time2) best_time = time1;
	else best_time = time2;

	Solution sol(LPT, best_time);
	for (int i = 0; i < tasks.size(); i++) sol.addToSolution(tasks[i].second);

	return sol;
}

Solution Problem::PD() {
	int time = 0;
	std::vector<int> tasks;
	int sumPj = 0;
	int kl = 0;
	for (int i = 0; i < n; i++) sumPj += Pj[i];
	kl = (int)floor(sumPj / 2 + 1);

	int** T = new int* [n + 1];
	for (int i = 0; i <= n; i++) T[i] = new int[kl];


	//Wype³nienie pierwszej kolumny 1 a reszta 0
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k < kl; k++) {
			if (k == 0) T[j][k] = 1;
			else T[j][k] = 0;
		}
	}

	//Uzupe³nienie
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k < kl; k++) {
			if ((T[j - 1][k] == 1) || ((k >= Pj[j - 1]) && (T[j - 1][k - Pj[j - 1]] == 1)))
				T[j][k] = 1;
		}
	}
	
	//Display
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < kl; j++)
			std::cout << T[i][j] << " ";
		std::cout << std::endl;
	}
	
	//backtrack
	int i;
	int k = kl - 1;
	while (k != 0) {
		for (i = 1; i <= n; i++) {
			if (T[i][k] == 1) {
				time += Pj[i - 1];
				k = k - Pj[i - 1];
				tasks.push_back(i - 1);
				break;
			}
		}
		if (i == n + 1) 
			k--;
	}

	Solution sol(PDalg, sumPj - time);
	for (int i = 0; i < tasks.size(); i++) sol.addToSolution(tasks[i]);

	return sol;
}


void Problem::displayProblem()
{

	for (int i = 0; i < n; ++i) std::cout << Pj[i] << " ";
	std::cout << std::endl;
}
