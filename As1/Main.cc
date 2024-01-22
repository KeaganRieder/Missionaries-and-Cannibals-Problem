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
#include <string>
using namespace std;

//constants
//2d array showing possible moves for missionaries and cannibals 
const int ACTIONS[][2] = { {1,0}, {0,1}, {2,0}, {0,2}, {1,1} };

//
//structs decleration 
//

// struct used to store every varible which relates to a state
struct State
{
    int missionariesLeft;
    int cannibalsLeft;

    int missionariesBoat;
    int cannibalsBoat;

    int missionariesRight;
    int cannibalsRight;
};

//
//function decleration 
//
bool ValidState(const State& state);
bool StatExsits(const State& state);
string FormatState(const State& state);
void GenerateNextState(const State& state);
void Solve();

//global varibles
map<string, State> states;

// 
// main program loop
//
int main(){

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
    //are boat missionaries not outnumbered
    bool BoatValid = state.missionariesBoat >= state.cannibalsBoat;

    //are missionaries not outnumber in any group
    return leftValid && RightValid && BoatValid;
}
bool StatExsits(const State& state){
    string formatedState = FormatState(state);
    return !(states.find(formatedState) == states.end());
}

string FormatState(const State& state){
    string formatedState = to_string(state.missionariesLeft) + "," + to_string(state.cannibalsLeft) + "|" + to_string(state.cannibalsBoat)
        + "," + to_string(state.cannibalsBoat)+ "|" + to_string(state.missionariesRight) + "," + to_string(state.cannibalsRight);     

    return formatedState;
}

void GenerateNextState(const State& state){
    //ACTIONS[][2] = { {1,0}, {0,1}, {2,0}, {0,2}, {1,1} };

    // if (StatExsits())
    // {
    //     /* code */
    // }
    
}

void Solve(){
    State inital = {3,3,0,0,0,0};
    State goalState = {0,0,0,0,3,3};

    queue<State> stateQueue;
    stateQueue.push(inital);
    states[FormatState(inital)] = inital;
    
    while (!stateQueue.empty())
    {
        State currentState = stateQueue.front();
        stateQueue.pop();

        GenerateNextState(currentState);
    } 
}