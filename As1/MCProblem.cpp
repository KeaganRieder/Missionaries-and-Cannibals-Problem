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

//constants
//2d array showing possible moves for missionaries and cannibals 
const vector<pair<int,int>> MOVES = {{1,0},{2,0},{0,1},{0,2}, {1,1}};
// const int ACTIONS[][2] = { {1,0}, {0,1}, {2,0}, {0,2}, {1,1} };
const int MAX_CAPACITY = 2;

//
//structs decleration 
//

// struct used to store every varible which relates to a state
struct State
{
    int missionariesLeft;
    int cannibalsLeft;

    int missionariesRight;
    int cannibalsRight;

    int missionariesRight;
    int cannibalsRight;
    int boatSide; // 0 for left, 1 for right

    bool operator==(const State& other) const {
        return missionariesLeft == other.missionariesLeft &&
               cannibalsLeft == other.cannibalsLeft &&
               missionariesRight == other.missionariesRight &&
               cannibalsRight == other.cannibalsRight &&
               boatSide == other.boatSide;
    }
};

//
//function decleration 
//
bool ValidState(const State& state);
bool StatExsits(const State& state);
bool Solved(const State& state);
string FormatState(const State& state);
void GenerateNextState(const State& state);
void Solve();

//global varibles
map<string, State> states;
queue<State> stateQueue;

// 
// main program loop
//
int main(){

    cout<<"\n bfs start \n";
    Solve();
    cout<<"\n bfs end \n";
    return 0;
}

//
//function implemention 
//
bool ValidState(const State& state){
    //are left missionaries not outnumbered
    bool leftValid = state.missionariesLeft >= state.cannibalsLeft;
    //are right missionaries not outnumbered
    bool RightValid = state.missionariesRight >= state.cannibalsRight;

    //are missionaries not outnumber in any group
    return leftValid && RightValid;
}

bool StatExsits(const State& state){
    string formatedState = FormatState(state);
    return !(states.find(formatedState) == states.end());
}

bool Solved(const State& state){
    State goalState = {0,0,3,3,1};
    return ValidState(state) && state == goalState;    
}


string FormatState(const State& state){
    string formatedState = to_string(state.missionariesLeft) + "," + to_string(state.cannibalsLeft) +
         "|" + to_string(state.missionariesRight) + "," + to_string(state.cannibalsRight) +
         "|" + to_string(state.boatSide);     

    return formatedState;
}

void GenerateNextState(const State& currentState){
    //possible MOVES = {{1,0},{2,0},{0,1},{0,2}, {1,1}};
    //run through every possible move based on the side 
    for (const auto& moves : MOVES)
    {
        State nextState;
            
            //on left
            if(currentState.boatSide == 0){
                //remove missionaries and cannables from left then move them to write
                nextState = {currentState.missionariesLeft - moves.first, currentState.missionariesLeft - moves.second, 
                    currentState.missionariesLeft + moves.first, currentState.missionariesLeft + moves.second, 1};
            }
            //on right
            else{
                //?
                nextState = {currentState.missionariesLeft - moves.first, currentState.missionariesLeft - moves.second, 
                    currentState.missionariesLeft + moves.first, currentState.missionariesLeft + moves.second, 0};
            }

            //making sure nextState is valid and not visted yet
            if (!StatExsits(nextState) && ValidState(nextState))
            {
                stateQueue.push(nextState);
                states[FormatState(nextState)] = nextState;
            }
    }    
}

void Solve(){
    State inital = {3,3,0,0,0};
   
    stateQueue.push(inital);
    states[FormatState(inital)] = inital;
    
    while (!stateQueue.empty())
    {
        State currentState = stateQueue.front();
        stateQueue.pop();

        if (Solved(currentState))
        {
            cout<<"\n solved\n";
            break;
        }        

        GenerateNextState(currentState);
    } 
    cout<<"\n not solved\n";
}