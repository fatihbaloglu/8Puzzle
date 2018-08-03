#ifndef include_hpp
#define include_hpp

#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include "Trie.hpp"
//#define PRINT_LOG

static const int goal_state[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
#define X 3

using namespace std;

struct Node
{
    Node *parent;
    int matrix[X][X], cost, depth;
    pair<int, int> blank_tiles;
};
class Searches
{
private:
    enum moves{
        LEFT,
        UP,
        RIGHT,
        DOWN
    };
    struct uniform_comp
    {
        bool operator()(const Node* lhs, const Node* rhs) const
        {
            return (lhs->depth) > (rhs->depth);
        }
    };
    struct greedy_comp
    {
        bool operator()(const Node* lhs, const Node* rhs) const
        {
            return (lhs->cost) > (rhs->cost);
        }
    };
    struct astar_comp
    {
        bool operator()(const Node* lhs, const Node* rhs) const
        {
            return (lhs->cost + lhs->depth) > (rhs->cost + rhs->depth);
        }
    };
    int initial_state[X][X], number_of_nodes_expanded, nodes_saved_in_memory, optimal_solution_step;
    Trie visited;
    queue<Node*> successor;
    stack<Node*> depth_successor;
    priority_queue<Node*, vector<Node*>, uniform_comp> uniform_cost_successor;
    priority_queue<Node*, vector<Node*>, greedy_comp> greedy_best_successor;
    priority_queue<Node*, vector<Node*>, astar_comp> astart_successor;
    double duration;
    
    void _BFS(int [X][X]);
    void _DFS(int [X][X]);
    void _UCS(int [X][X]);
    void _IDS(int [X][X]);
    void _GBS(int [X][X]);
    void _ASS(int [X][X]);
    int _nonValidPlaces(int [X][X]);
    int _manhattanDistance(int [X][X]);
    bool _isGoalState(int [X][X]);
    pair<int, int> _findGoalState(int);
    pair<int, int> _findBlank(int[X][X]);
    bool _movement(pair<int, int>, moves);
    void _printCurrentState(int [X][X]);
    Node *newNode(int [X][X], pair<int, int>, Node*);
    Node *newNode(int [X][X], pair<int, int>, int, Node*);
    void printResult(Node*);
public:
    Searches(int[X][X]);
    void Breadth_First_Search();
    void Depth_First_Search();
    void Uniform_Cost_Search();
    void Iterative_Deepenin_Search();
    void Greedy_Best_Search();
    void A_Star_Search();
    ~Searches() {}
};

#endif /* include_hpp */
