#include "include.hpp"

Searches::Searches(int our_initial_state[X][X])
{
    memcpy(initial_state, our_initial_state, sizeof initial_state);
}

int Searches::_nonValidPlaces(int state[X][X])
{
    int nonvalid = 0;
    for(int i = 0; i < X; i++)
        for(int j = 0; j < X; j++)
            if(state[i][j] != goal_state[i][j])
                nonvalid++;
    return nonvalid;
}

pair<int, int> Searches::_findGoalState(int number)
{
    pair<int, int> result;
    for(int i = 0; i < X; i++)
        for(int j = 0; j < X; j++)
            if(goal_state[i][j] == number)
                return make_pair(i,j);
    return make_pair(0, 0);
}

int Searches::_manhattanDistance(int state[X][X])
{
    int distance = 0;
    for(int i = 0; i < X; i++)
    {
        for(int j = 0; j < X; j++)
        {
            if(state[i][j] != goal_state[i][j])
            {
                pair<int, int> result = _findGoalState(state[i][j]);
                distance += abs(i - result.first);
                distance += abs(j - result.second);
            }
        }
    }
    return distance;
}

bool Searches::_isGoalState(int state [X][X])
{
    for (int i = 0; i < X; i++)
        for(int j = 0; j < X; j++)
            if(state[i][j] != goal_state[i][j])
                return false;
    return true;
}

pair<int, int> Searches::_findBlank(int state[X][X])
{
    pair<int, int> result;
    for(int i = 0; i < X; i++)
        for(int j = 0; j < X; j++)
            if(state[i][j] == 0)
                return make_pair(i,j);
    return make_pair(0, 0);
}

bool Searches::_movement(pair<int, int> current, moves move)
{
    switch (move) {
        case LEFT:
            if(0 == current.second)
                return false;
            else
                return true;
            break;
        case UP:
            if(0 == current.first)
                return false;
            else
                return true;
        case RIGHT:
            if(2 == current.second)
                return false;
            else
                return true;
        case DOWN:
            if(2 == current.first)
                return false;
            else
                return true;
        default:
            cout << "This should not happen!!" << endl;
            break;
    }
    return false;
}

void Searches::_printCurrentState(int state[X][X])
{
    for (int i = 0; i < X; i++)
        for(int j = 0; j < X; j++)
            cout << state[i][j] << "\t";
}

void Searches::_BFS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, NULL), *noww;
    successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    while(true)
    {
        if (!successor.size())
        {
#ifdef PRINT_LOG
            cout << "BFS could not find the solution" << endl;
#endif
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            return;
        }
        noww = successor.front();
        successor.pop();
        if(!visited.search(noww->matrix))
        {
            number_of_nodes_expanded++;
            visited.insert(noww->matrix);
            if(_movement(noww->blank_tiles, LEFT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, UP))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, RIGHT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, DOWN))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
        }
    }
}

void Searches::_DFS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, NULL), *noww;
    depth_successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    while(true)
    {
        if (depth_successor.size() == 0)
        {
            cout << "DFS could not find the solution" << endl;
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            return;
        }
        noww = depth_successor.top();
        depth_successor.pop();
        if(!visited.search(noww->matrix))
        {
            number_of_nodes_expanded++;
            visited.insert(noww->matrix);
            if(_movement(noww->blank_tiles, DOWN))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    depth_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, RIGHT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    depth_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, UP))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    depth_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, LEFT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww);
                    depth_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
        }
    }
}

void Searches::_IDS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, 0, NULL), *noww;
    depth_successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    for(int i = 1; i < INT_MAX; i++)
    {
        while(true)
        {
            if (depth_successor.size() == 0)
            {
                cout << "IDS could not find the solution" << endl;
                duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                return;
            }
            noww = depth_successor.top();
            depth_successor.pop();
            number_of_nodes_expanded++;
            
            if(!visited.search(noww->matrix))
            {
                visited.insert(noww->matrix);
                if(noww->depth == i+1)
                {
                    break;
                }
                if(_movement(noww->blank_tiles, DOWN))
                {
                    memcpy(temp, noww->matrix, sizeof temp);
                    swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                    newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                    if(_isGoalState(temp))
                    {
#ifdef PRINT_LOG
                        cout << "Solution is found printing result!" << endl;
#endif
                        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        printResult(newone);
                        nodes_saved_in_memory++;
                        return;
                    }
                    if(!visited.search(temp))
                    {
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        depth_successor.push(newone);
                        nodes_saved_in_memory++;
                    }
                }
                if(_movement(noww->blank_tiles, RIGHT))
                {
                    memcpy(temp, noww->matrix, sizeof temp);
                    swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                    newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                    if(_isGoalState(temp))
                    {
#ifdef PRINT_LOG
                        cout << "Solution is found printing result!" << endl;
#endif
                        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        printResult(newone);
                        nodes_saved_in_memory++;
                        return;
                    }
                    if(!visited.search(temp))
                    {
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        depth_successor.push(newone);
                        nodes_saved_in_memory++;
                    }
                }
                if(_movement(noww->blank_tiles, UP))
                {
                    memcpy(temp, noww->matrix, sizeof temp);
                    swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                    newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                    if(_isGoalState(temp))
                    {
#ifdef PRINT_LOG
                        cout << "Solution is found printing result!" << endl;
#endif
                        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        printResult(newone);
                        nodes_saved_in_memory++;
                        return;
                    }
                    if(!visited.search(temp))
                    {
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        depth_successor.push(newone);
                        nodes_saved_in_memory++;
                    }
                }
                if(_movement(noww->blank_tiles, LEFT))
                {
                    memcpy(temp, noww->matrix, sizeof temp);
                    swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                    newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                    if(_isGoalState(temp))
                    {
#ifdef PRINT_LOG
                        cout << "Solution is found printing result!" << endl;
#endif
                        duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        printResult(newone);
                        nodes_saved_in_memory++;
                        return;
                    }
                    if(!visited.search(temp))
                    {
                        Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                        depth_successor.push(newone);
                        nodes_saved_in_memory++;
                    }
                }
            }
        }
    }
}

void Searches::_UCS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, 0, NULL), *noww;
    uniform_cost_successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    while(true)
    {
        if (uniform_cost_successor.size() == 0)
        {
            cout << "UCS could not find the solution" << endl;
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            return;
        }
        noww = uniform_cost_successor.top();
        uniform_cost_successor.pop();
        
        if(!visited.search(noww->matrix))
        {
            visited.insert(noww->matrix);
            number_of_nodes_expanded++;
            if(_movement(noww->blank_tiles, LEFT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    uniform_cost_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, UP))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    uniform_cost_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, RIGHT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    uniform_cost_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, DOWN))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    uniform_cost_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
        }
    }
}

void Searches::_GBS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, 0, NULL), *noww;
    root->cost = _manhattanDistance(root->matrix);
    greedy_best_successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    while(true)
    {
        if (greedy_best_successor.size() == 0)
        {
            cout << "GBS could not find the solution" << endl;
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            return;
        }
        noww = greedy_best_successor.top();
        greedy_best_successor.pop();
        
        if(!visited.search(noww->matrix))
        {
            visited.insert(noww->matrix);
            number_of_nodes_expanded++;
            if(_movement(noww->blank_tiles, LEFT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    greedy_best_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, UP))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    greedy_best_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, RIGHT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    greedy_best_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, DOWN))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    greedy_best_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
        }
    }
}

void Searches::_ASS(int state[X][X])
{
    pair<int, int> current = _findBlank(state), newstate;
    Node* root = newNode(state, current, 0, NULL), *noww;
    root->cost = _manhattanDistance(root->matrix);
    astart_successor.push(root);
    number_of_nodes_expanded = 0;
    optimal_solution_step = 0;
    nodes_saved_in_memory = 1;
    int temp[X][X];
    clock_t start = clock();
    
    while(true)
    {
        if (astart_successor.size() == 0)
        {
            cout << "ASS could not find the solution" << endl;
            duration = (clock() - start)/(double)CLOCKS_PER_SEC;
            return;
        }
        noww = astart_successor.top();
        astart_successor.pop();
        if(!visited.search(noww->matrix))
        {
            visited.insert(noww->matrix);
            number_of_nodes_expanded++;
            if(_movement(noww->blank_tiles, LEFT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second-1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second-1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    astart_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, UP))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first-1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first-1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    astart_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, RIGHT))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first][noww->blank_tiles.second+1]);
                newstate = make_pair(noww->blank_tiles.first, noww->blank_tiles.second+1);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    astart_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
            if(_movement(noww->blank_tiles, DOWN))
            {
                memcpy(temp, noww->matrix, sizeof temp);
                swap(temp[noww->blank_tiles.first][noww->blank_tiles.second], temp[noww->blank_tiles.first+1][noww->blank_tiles.second]);
                newstate = make_pair(noww->blank_tiles.first+1, noww->blank_tiles.second);
                if(_isGoalState(temp))
                {
#ifdef PRINT_LOG
                    cout << "Solution is found printing result!" << endl;
#endif
                    duration = (clock() - start)/(double)CLOCKS_PER_SEC;
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    printResult(newone);
                    nodes_saved_in_memory++;
                    return;
                }
                if(!visited.search(temp))
                {
                    Node* newone = newNode(temp, newstate, noww->depth+1, noww);
                    newone->cost = _manhattanDistance(newone->matrix);
                    astart_successor.push(newone);
                    nodes_saved_in_memory++;
                }
            }
        }
    }
}

Node *Searches::newNode(int matrix[X][X], pair<int, int> current, int depth, Node *parent)
{
    Node *newnode = new Node;
    newnode->parent = parent;
    newnode->depth = depth;
    newnode->cost = INT_MAX;
    memcpy(newnode->matrix, matrix, sizeof newnode->matrix);
    newnode->blank_tiles = make_pair(current.first, current.second);
    return newnode;
}

Node *Searches::newNode(int matrix[X][X], pair<int, int> current, Node *parent)
{
    Node *newnode = new Node;
    newnode->parent = parent;
    memcpy(newnode->matrix, matrix, sizeof newnode->matrix);
    newnode->blank_tiles = make_pair(current.first, current.second);
    return newnode;
}

void Searches::printResult(Node *root)
{
    if (root == NULL)
        return;
    printResult(root->parent);
    optimal_solution_step++;
#ifdef PRINT_LOG
    _printCurrentState(root->matrix);
    cout << endl;
#endif
}

void Searches::Breadth_First_Search()
{
    _BFS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}

void Searches::Depth_First_Search()
{
    _DFS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}

void Searches::Iterative_Deepenin_Search()
{
    _IDS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}

void Searches::Uniform_Cost_Search()
{
    _UCS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}

void Searches::Greedy_Best_Search()
{
    _GBS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}

void Searches::A_Star_Search()
{
    _ASS(initial_state);
    cout << "Number of expanded nodes : " <<  number_of_nodes_expanded << "\nNumber of nodes saved in memory : " << nodes_saved_in_memory
    << "\nSolution step count : " << optimal_solution_step << "\nTime spent(ms) : " << duration*1000 << endl;
}
