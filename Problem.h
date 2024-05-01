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
	

	std::vector<int> Generate(int a, int start, int limit);

	Solution BruteForce_2machine(std::vector<int> Pj, int n);

	Solution BruteForce_3machine(std::vector<int> Pj, int n);

	Solution LSAAlgorithm(std::vector<int> Pj, int n);

	Solution LPTAlgorithm(std::vector<int> Pj, int n);

	Solution PTASAlgorithm(int k, std::vector<int> Pj, int n);

	Solution PTAS3Algorithm(int k, std::vector<int> Pj, int n);

	Solution PDAlgorithm(int l, std::vector<int> Pj, int n);

	Solution FPTASAlgorithm(int k, std::vector<int> Pj, int n);

	Solution PD3Algorithm(std::vector<int> Pj, int n);

	void displayProblem(std::vector<int> Pj, int n);

	struct trit {
		bool a = false;
		bool b = false;
		int value() { return ( !a && !b) ? 0 : (( a && !b ) ? 1 : 2); };
		trit& operator++() {
			if (a == false) a = true;
			else if (b == false) b = true;
			else { a = false; b = false; }
			return *this;
		};
	};
	struct int64_trit {
		trit value[64];
		int operator>>(int shiftAmount) {
			return value[shiftAmount].value();
		};
		int64_trit& operator++() {
			int i = 0;
			while (true) {
				if ((++value[i++]).value() != 0) break;
				if (i == 64) break;
			}
			return *this;
		};
	};

