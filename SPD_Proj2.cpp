

#include <iostream>
#include "Problem.h"

int main()
{
    Problem prb(25,100);
    prb.displayProblem();
    Solution sol = prb.BruteForce_2machine();
    sol.displaySolution();
}