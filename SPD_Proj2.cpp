

#include <iostream>
#include "Problem.h"
#include <chrono>

int main()
{
    Problem prb(25,10);
    prb.displayProblem();
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution sol = prb.BruteForce_2machine();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;

    sol = prb.LSAAlgorithm();
    sol.displaySolution();

    sol = prb.LPTAlgorithm();
    sol.displaySolution();

    sol = prb.PD();
    sol.displaySolution();
}