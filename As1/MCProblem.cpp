/*
################################################################################
    Summary
    progarm designed to solve The missionaries and cannibals problem, through
    using a variation of the bredth first search algrothim

################################################################################
*/
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <string>
using namespace std;

//
// structs decleration
//

// struct used to store every varible which relates to a state
struct State
{
    int missionaries;
    int cannibals;

    int boatSide; // 0 for left, 1 for right

    string move;
    int step;

    bool operator==(const State &other) const
    {
        return missionaries == other.missionaries &&
               cannibals == other.cannibals &&
               boatSide == other.boatSide;
    }
};

// constants
// 2d array showing possible moves for missionaries and cannibals
const vector<pair<int, int>> MOVES = {{1, 0}, {2, 0}, {0, 1}, {0, 2}, {1, 1}};
const State GOAL_STATE = {0, 0, 1}; // all on left side

//
// function decleration
//
bool ValidState(const State &state);
bool StatExsits(const State &state);
bool Solved(const State &state);
string FormatState(const State &state);
void GenerateNextState(const State &state);
bool Solve();
void OuputSolution();

// global varibles
map<string, State> states;
map<string, string> stateOrder; // stores order of states
queue<State> stateQueue;
//
// main program loop
//
int main()
{
    cout << "--- Missionaries and cannibals problem solver---\n";
    Solve();
    OuputSolution();

    // hold power shell
    string temp;
    cin >> temp;
    return 0;
}

//
// function implemention
//
bool ValidState(const State &state)
{
    bool outOfBounds = (state.missionaries < 0 || state.missionaries > 3) || (state.cannibals < 0 || state.cannibals > 3);
    bool notOutNumbered = state.missionaries == 0 || state.missionaries >= state.cannibals;
    // check if state is valid (no missionaries outnummber by cannibals)
    return notOutNumbered && !outOfBounds;
}

bool StatExsits(const State &state)
{
    string formatedState = FormatState(state);
    return !(states.find(formatedState) == states.end());
}

bool Solved(const State &state)
{
    return ValidState(state) && state == GOAL_STATE;
}

string FormatState(const State &state)
{
    string formatedState = to_string(state.missionaries) + "," + to_string(state.cannibals) +
                           "|" + to_string(state.boatSide);
    return formatedState;
}

void GenerateNextState(const State &currentState)
{
    // possible MOVES = {{1,0},{2,0},{0,1},{0,2}, {1,1}};
    // run through every possible move based on the side
    for (const auto &moves : MOVES)
    {
        State nextState;
        // on left
        if (currentState.boatSide == 0)
        {
            nextState = {currentState.missionaries - moves.first, currentState.cannibals - moves.second, 1 - currentState.boatSide};
            nextState.move = "move missionaries: " + to_string(moves.first) + " | cannibals " + to_string(moves.second) + " right";
        }
        // on right
        else
        {
            //negtiave is produced here need fixed
            nextState = {currentState.missionaries + moves.first, currentState.cannibals + moves.second, 1 - currentState.boatSide};
            nextState.move = "move missionaries: " + to_string(moves.first) + " | cannibals: " + to_string(moves.second) + " left";
        }
        // making sure nextState is valid and not visted yet
        if (!StatExsits(nextState) && ValidState(nextState)) // this needs checking
        {
            nextState.step = currentState.step + 1;
            stateQueue.push(nextState);
            states[FormatState(nextState)] = nextState;
            stateOrder[FormatState(nextState)] = FormatState(currentState);
        }
    }
}

bool Solve()
{
    State inital = {3, 3, 0};
    inital.step = 0;
    stateQueue.push(inital);
    states[FormatState(inital)] = inital;
    stateOrder[FormatState(inital)] = "Starting State";

    while (!stateQueue.empty())
    {
        State currentState = stateQueue.front();
        stateQueue.pop();

        if (Solved(currentState))
        {
            return true;
        }

        GenerateNextState(currentState);
    }
    return false;
}

void OuputSolution()
{
    State inital = {3, 3, 0};
    string stateKey = FormatState(GOAL_STATE);

    cout << "it takes a total of " << states[stateKey].step << " steps to get all the Missionaries and cannibals \n"
         << "from one side to the other. \n"
         << "the following are the steps required to do this:\n\n";

    while (stateOrder[stateKey] != "Starting State")
    {
        State current = states[stateKey];
        cout << "> Step " << current.step << "\n";
        cout << "> cannibals left Side : " << to_string(current.cannibals) << " | Missionaries left Side : " << to_string(current.missionaries) << "\n";
        cout << "> cannibals right Side : " << to_string(3 - current.cannibals) << " | Missionaries right Side : " << to_string(3 - current.missionaries) << "\n";
        cout << "> " << current.move << "\n\n";

        stateKey = stateOrder[stateKey];
    }
    cout << "> Start \n";
    cout << "> cannibals left Side : " << to_string(states[FormatState(inital)].cannibals)
         << " | Missionaries left Side : " << to_string(states[FormatState(inital)].missionaries) << "\n";
    cout << "> cannibals right Side : " << to_string(3 - states[FormatState(inital)].cannibals)
         << " | Missionaries right Side : " << to_string(3 - states[FormatState(inital)].missionaries) << "\n";
}