

#include <iostream>
#include "Problem.h"
#include <chrono>
#include <fstream>
#include <string.h>

Solution emptySol() {
    Solution sol;
    return sol;
}
int main() {

}
int GenerateFor2Machines()
{
    int n = 30;
    const char* prefix[12] = {
    "\\makecell{2/10\\\\[0px] [1-10]} & ",
    "\\makecell{2/10\\\\[0px] [10-20]} & ",
    "\\makecell{2/10\\\\[0px] [50-100]} & ",
    "\\makecell{2/20\\\\[0px] [1-10]} & ",
    "\\makecell{2/20\\\\[0px] [10-20]} & ",
    "\\makecell{2/20\\\\[0px] [50-100]} & ",
    "\\makecell{2/36\\\\[0px] [1-10]} & ",
    "\\makecell{2/36\\\\[0px] [10-20]} & ",
    "\\makecell{2/36\\\\[0px] [50-100]} & ",
    "\\makecell{2/50\\\\[0px] [1-10]} & ",
    "\\makecell{2/50\\\\[0px] [10-20]} & ",
    "\\makecell{2/50\\\\[0px] [50-100]} & ",
    };
    int ns[4] = { 10,20,36,50 };
    int starts[3] = { 1,10,50 };
    int ends[3] = { 10,20,100 };
    //finish times
    int brute_ft, PD_ft, LSA_ft, LPT_ft;
    //time differences
    int brute_td, PD_td, LSA_td, LPT_td;
    std::fstream file, file2;
    Solution sol = emptySol();
    file.open("C:\\Users\\axeel\\Desktop\\tabela1.txt", std::ios::out);
    file2.open("C:\\Users\\axeel\\Desktop\\tabela2.txt", std::ios::out);
    for (int i = 0; i < 12; ++i) {
        n = ns[i/3];
        std::vector<int> Problem = Generate(n, starts[i % 3], ends[i % 3]);
        displayProblem(Problem, n);
        std::chrono::steady_clock::time_point begin, end;

        if (n <= 40) {
            begin = std::chrono::steady_clock::now();
            sol = BruteForce_2machine(Problem, n);
            end = std::chrono::steady_clock::now();
            sol.displaySolution();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl << std::endl;

            brute_ft = sol.getFinishTime();
            brute_td = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        }

        begin = std::chrono::steady_clock::now();
        sol = LSAAlgorithm(Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;

        LSA_ft = sol.getFinishTime();
        LSA_td = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        
        begin = std::chrono::steady_clock::now();
        sol = PDAlgorithm(2, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;

        PD_ft = sol.getFinishTime();
        PD_td = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

        begin = std::chrono::steady_clock::now();
        sol = LPTAlgorithm(Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;

        LPT_ft = sol.getFinishTime();
        LPT_td = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        if (PD_ft != brute_ft) std::cout << "LOL MISTAKE";
        file << prefix[i] << "\\makecell{" << LSA_ft << "\\\\[0px][" << (float)(LSA_ft - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & " << LSA_td << " & ";
        file << "\\makecell{" << LPT_ft << "\\\\[0px][" << (float)(LPT_ft - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & " << LPT_td << " & ";
        file << PD_ft << " & " << PD_td << " & ";
        if (n <= 36)
            file << brute_td << "\\\\ \\hline" << std::endl;
        else
            file << "x" << "\\\\ \\hline" << std::endl;


        file2 << prefix[i];
        begin = std::chrono::steady_clock::now();
        sol = PTASAlgorithm(n / 2, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px][" << (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " & ";

        begin = std::chrono::steady_clock::now();
        sol = PTASAlgorithm(2 * n / 3, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px]["<< (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " & ";

        begin = std::chrono::steady_clock::now();
        sol = PTASAlgorithm(3 * n / 4, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px][" << (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " & ";
        
        begin = std::chrono::steady_clock::now();
        sol = FPTASAlgorithm(2, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px][" << (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " & ";

        begin = std::chrono::steady_clock::now();
        sol = FPTASAlgorithm(3, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px][" << (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " & ";

        begin = std::chrono::steady_clock::now();
        sol = FPTASAlgorithm(4, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;
        file2 << "\\makecell{" << sol.getFinishTime() << "\\\\[0px][" << (float)(sol.getFinishTime() - PD_ft) * 100.0 / (float)PD_ft << "\\%]} & ";
        file2 << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "\\\\ \\hline" << std::endl;

        
        /*begin = std::chrono::steady_clock::now();
        sol = BruteForce_3machine(Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl << std::endl;

        begin = std::chrono::steady_clock::now();
        sol = PTAS3Algorithm(n / 2, Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;

        begin = std::chrono::steady_clock::now();
        sol = PD3Algorithm(Problem, n);
        end = std::chrono::steady_clock::now();
        sol.displaySolution();
        std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl << std::endl;*/


    }
    file.close();
    file2.close();

}

