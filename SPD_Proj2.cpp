

#include <iostream>
#include "Problem.h"
#include <chrono>

int main()
{
    int n = 17;
    std::vector<int> Problem = Generate(n, 1, 10);
    displayProblem(Problem, n);
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Solution sol = BruteForce_2machine(Problem, n);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;

    begin = std::chrono::steady_clock::now();
    sol = BruteForce_3machine(Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;


    begin = std::chrono::steady_clock::now();
    sol = LSAAlgorithm(Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;



    begin = std::chrono::steady_clock::now();
    sol = LPTAlgorithm(Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;


    begin = std::chrono::steady_clock::now();
    sol = PDAlgorithm(2, Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;


    begin = std::chrono::steady_clock::now();
    sol = PTASAlgorithm(n / 2, Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;

    begin = std::chrono::steady_clock::now();
    sol = PTAS3Algorithm(n / 2, Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;



    begin = std::chrono::steady_clock::now();
    sol = FPTASAlgorithm(2, Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;

    begin = std::chrono::steady_clock::now();
    sol = PD3Algorithm(Problem, n);
    end = std::chrono::steady_clock::now();
    sol.displaySolution();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;


}