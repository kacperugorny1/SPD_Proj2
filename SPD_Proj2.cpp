

#include <iostream>
#include "Problem.h"
#include <chrono>

int main()
{
    int n = 16;
    std::vector<int> Problem = Generate(n, 20);
    displayProblem(Problem, n);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution sol = BruteForce_2machine(Problem, n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;

    begin = std::chrono::steady_clock::now();
    sol = BruteForce_3machine(Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;



    sol = LSAAlgorithm(Problem, n);
    sol.displaySolution();

    sol = LPTAlgorithm(Problem, n);
    sol.displaySolution();

    sol = PD(Problem, n);
    sol.displaySolution();

    sol = PTASlgorithm(n/2 ,Problem, n);
    sol.displaySolution();

}