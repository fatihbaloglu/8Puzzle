#include <iostream>
#include "include.hpp"
#include "Trie.hpp"

//#define BREADTH_FIRST_SEARCH
//#define DEPTH_FIRST_SEARCH
//#define ITERATIVE_DEEPENING_SEARCH
//#define UNIFORM_COST_SEARCH
//#define GREEDY_BEST_FIRST_SEARCH
#define A_STAR_SEARCH

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "== 8 Puzzle Problem ==" << endl;
    int first[3][3] = { {0, 1, 3}, {4, 2, 5}, {7, 8, 6} };
    int second[3][3] = { {1, 2, 3}, {4, 6, 0}, {8, 7, 5} };
    int third[3][3] = { {1, 8, 2}, {0, 4, 3}, {7, 6, 5} };
    int fourth[3][3] = { {8, 0, 6}, {5, 4, 7}, {2, 3, 1} };
    int fifth[3][3] = { {4, 5, 0}, {8, 3, 6}, {2, 1, 7} };
    int sixth[3][3] = { {0, 3, 8}, {4, 1, 7}, {2, 6, 5} };
    int seventh[3][3] = { {8, 6, 7}, {2, 5, 4}, {3, 0, 1} };
    int eighth[3][3] = { {6, 4, 7}, {8, 5, 0}, {3, 2, 1} };
    int nineth[3][3] = { {6, 0, 3}, {2, 1, 8}, {5, 4, 7} };
    int tenth[3][3] = { {3, 4, 0}, {6, 1, 8}, {2, 5, 7} };
#ifdef BREADTH_FIRST_SEARCH
    cout << "Breadth First Search Solution" << endl;
#endif
#ifdef DEPTH_FIRST_SEARCH
    cout << "Depth First Search Solution" << endl;
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    cout << "Iterative Deepining Search Solution" << endl;
#endif
#ifdef UNIFORM_COST_SEARCH
    cout << "Uniform Cost Search Solution" << endl;
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    cout << "Greedy Best First Search Solution" << endl;
#endif
#ifdef A_STAR_SEARCH
    cout << "A* Search Solution" << endl;
#endif
 
    cout << "\nProblem 1 : 0 1 3 4 2 5 7 8 6" << endl;

    Searches search1(first);
#ifdef BREADTH_FIRST_SEARCH
    search1.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search1.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search1.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search1.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search1.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search1.A_Star_Search();
#endif
    
    cout << "\nProblem 2 : 1 2 3 4 6 0 8 7 5" << endl;

    Searches search2(second);
#ifdef BREADTH_FIRST_SEARCH
    search2.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search2.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search2.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search2.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search2.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search2.A_Star_Search();
#endif
    
    cout << "\nProblem 3 : 1 8 2 0 4 3 7 6 5" << endl;
    
    Searches search3(third);
#ifdef BREADTH_FIRST_SEARCH
    search3.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search3.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search3.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search3.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search3.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search3.A_Star_Search();
#endif
    
    cout << "\nProblem 4 : 8 0 6 5 4 7 2 3 1" << endl;
    
    Searches search4(fourth);
#ifdef BREADTH_FIRST_SEARCH
    search4.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search4.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search4.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search4.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search4.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search4.A_Star_Search();
#endif
    
    cout << "\nProblem 5 : 4 5 0 8 3 6 2 1 7" << endl;
    
    Searches search5(fifth);
#ifdef BREADTH_FIRST_SEARCH
    search5.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search5.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search5.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search5.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search5.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search5.A_Star_Search();
#endif
    
    cout << "\nProblem 6 : 0 3 8 4 1 7 2 6 5" << endl;
    
    Searches search6(sixth);
#ifdef BREADTH_FIRST_SEARCH
    search6.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search6.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search6.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search6.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search6.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search6.A_Star_Search();
#endif
    
    cout << "\nProblem 7 : 8 6 7 2 5 4 3 0 1" << endl;
    
    Searches search7(seventh);
#ifdef BREADTH_FIRST_SEARCH
    search7.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search7.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search7.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search7.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search7.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search7.A_Star_Search();
#endif
    
    cout << "\nProblem 8 : 6 4 7 8 5 0 3 2 1" << endl;
    
    Searches search8(eighth);
#ifdef BREADTH_FIRST_SEARCH
    search8.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search8.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search8.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search8.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search8.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search8.A_Star_Search();
#endif
    
    cout << "\nProblem 9 : 6 0 3 2 1 8 5 4 7" << endl;
    
    Searches search9(nineth);
#ifdef BREADTH_FIRST_SEARCH
    search9.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search9.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search9.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search9.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search9.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search9.A_Star_Search();
#endif
    
    cout << "\nProblem 10 : 3 4 0 6 1 8 2 5 7" << endl;
    
    Searches search10(tenth);
#ifdef BREADTH_FIRST_SEARCH
    search10.Breadth_First_Search();
#endif
#ifdef DEPTH_FIRST_SEARCH
    search10.Depth_First_Search();
#endif
#ifdef ITERATIVE_DEEPENING_SEARCH
    search10.Iterative_Deepenin_Search();
#endif
#ifdef UNIFORM_COST_SEARCH
    search10.Uniform_Cost_Search();
#endif
#ifdef GREEDY_BEST_FIRST_SEARCH
    search10.Greedy_Best_Search();
#endif
#ifdef A_STAR_SEARCH
    search10.A_Star_Search();
#endif

    return 0;
}
