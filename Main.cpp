/*
################################################################################
    Summary
    progarm designed to solve The missionaries and cannibals problem, through
    using a variation of the bredth first search algrothim

################################################################################
*/
#include "State.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

//
//constants and global values
//
const vector<pair<int,int>> ACTIONS = {{1, 1},{1, 0}, {0, 1}, {2, 0}, {0, 2}};

queue<State*> stateQueue;
vector<State*> states;

//
//function Decleration
//
bool StateExsits(State* state);
void GetNextStates(State* state);
void Solve();
void OutPutSolution(State* state);

//
// main program loop
//
int main(){
    cout << "--- Missionaries and cannibals problem solver---\n";
    Solve();
}

//
//function implemenation
//
bool StateExsits(State* state){
    for (int i = 0; i < states.size(); i++)
    {
        if (states[i] == state)
        {
            //state exsits
            return true;
        }  
    }   
    
    //state doesn't
    return false;
}

void GetNextStates(State* lastState){
    int missionaries;
    int cannibals;
    int step;
    bool boatOnLeft; 
    
    // possible MOVES = {{1,0},{2,0},{0,1},{0,2}, {1,1}};
    // run through every possible move based on the side
    for (const auto &actions : ACTIONS)
    {
        //check which side last state was on
        if (lastState->BoatOnLeft())
        {   
            missionaries = lastState->LeftMissionaries() - actions.first;
            cannibals = lastState->LeftCannibals() - actions.second;
            step = lastState->Step() + 1;
            boatOnLeft = false;
        }
        else{
            //on right
            missionaries = lastState->LeftMissionaries() + actions.first;
            cannibals = lastState->LeftCannibals() + actions.second;
            step = lastState->Step() + 1;
            boatOnLeft = true;
        }

        State* nextState = new State(missionaries,cannibals,step,actions,boatOnLeft);
    
        //is next state Valid and if it exsits already
        if (nextState->ValidState() && !StateExsits(nextState))
        {           
            nextState->SetLastState(lastState);
            states.push_back(nextState);
            stateQueue.push(nextState);
        }
        else
        {
            delete nextState;
        }  
    }
}

void Solve(){
    State* state = new State(); //making inital state 3 missionaries, 3 cannibals on left side
    stateQueue.push(state);
    states.push_back(state);

    bool solved = false;

    while (!stateQueue.empty())
    {
        state = stateQueue.front(); stateQueue.pop();

        if (state->IsGoalState())
        {
            solved = true;
            cout<<"\nSolution Found\n";
            OutPutSolution(state);
            break;
        }
        
        GetNextStates(state);

    }   
    if (!solved)
    {
        cout<<"\nNo Solution Found\n";
    }
    
}

void OutPutSolution(State* state){
    State* currentState = state;

    cout << "it takes a total of " << currentState->Step() << " steps to get all the Missionaries and cannibals \n"
         << "from one side to the other. \n"
         << "the following are the steps required to do this:\n";

    while (currentState->GetLastState() != nullptr)
    {
        currentState->PrintState();
        currentState = currentState->GetLastState();
    }
    currentState->PrintState();  
    
    delete currentState;
}