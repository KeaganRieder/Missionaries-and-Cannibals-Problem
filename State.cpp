/*
    implemntation of state class
*/
#include "State.h"

#include <string>
using namespace std;

State::State()
{
    // makes state which is on left side, or often the start State
    missionaries = 3;
    cannibals = 3;
    step = 0;
    boatOnLeft = true;
    lastState = nullptr;
}

State::State(int missionaries, int cannibals, int step,pair<int,int> move, bool boatOnLeft)
{
    this->missionaries = missionaries;
    this->cannibals = cannibals;
    this->step = step;
    this->boatOnLeft = boatOnLeft;
    this->lastState = lastState;
    this->move = move;
    lastState = nullptr;
}

State::~State()
{
    delete lastState;
    lastState = nullptr;
}

void State::SetMissionaries(int missionaries) { this->missionaries = missionaries; }

void State::SetCannibals(int cannibals) { this->cannibals = cannibals; }

void State::SetStep(int step) { this->step = step; }

void State::SetLastState(State* lastState){this->lastState= lastState;}

int State::LeftMissionaries() { return missionaries; }

int State::LeftCannibals() { return cannibals; }

int State::RightMissionaries() { return 3 - missionaries; }

int State::RightCannibals() { return 3 - cannibals; }

int State::Step() { return step; }

bool State::BoatOnLeft(){return boatOnLeft;}

State* State::GetLastState(){return lastState;}

bool State::ValidState()
{
    // Missionaries aren't outnumber if there are none, or they are greater then or equail to
    // the amount of Cannibals 
    bool notOutNumber = (LeftMissionaries() == 0 || LeftMissionaries() >= LeftCannibals()) &&
                        (RightMissionaries() == 0 || RightMissionaries() >= RightCannibals());

    bool validAmount = (missionaries >= 0 && missionaries <= 3) && (cannibals >= 0 && cannibals <= 3);

    return notOutNumber && validAmount;
}

bool State::IsGoalState()
{
    bool goal = missionaries == 0 && cannibals == 0 && !boatOnLeft;

    return goal;
}

void State::PrintState()
{
    string side;

    if (boatOnLeft)
    {
        side = "left";
    }
    else
    {
        side = "right";
    }

    cout<<"\n> Step:" <<step <<"\n";
    cout<<"> Cannibals Left:  " << to_string(cannibals) <<" | Missionaries left: "<< to_string(missionaries) <<"\n";
    cout<<"> Cannibals right: " << to_string(RightCannibals()) <<" | Missionaries Side: "<< to_string(RightMissionaries())  <<"\n";
    cout<<"> Moved Cannibals: " << to_string(move.second) <<" | Missionaries: "<< to_string(move.first) << " " << side <<"\n";
}