/*
    class which defines what a state is for the missionary and cannibal problem
*/
#include <iostream>
#include <string>
using namespace std;

class State
{
private:
    int missionaries;
    int cannibals;
    int step;
    bool boatOnLeft;
    pair<int,int> move;
    State* lastState;

public:
    State();
    State(int missionaries, int cannibals, int step, pair<int,int> move, bool boatOnLeft);

    ~State();

    //
    // getters and setters
    //   
    void SetMissionaries(int missionaries);

    void SetCannibals(int cannibals);
    void SetStep(int step);
    void SetLastState(State* lastState);

    int Step();

    int LeftMissionaries();
    int LeftCannibals();
    int RightMissionaries();
    int RightCannibals();

    bool BoatOnLeft();
    bool ValidState();
    bool IsGoalState();

    State* GetLastState();

    void PrintState();

    //
    // op overload 
    //
    bool operator==(const State &other) const
    {
        return missionaries == other.missionaries &&
               cannibals == other.cannibals &&
               boatOnLeft == other.boatOnLeft;
    }
};
