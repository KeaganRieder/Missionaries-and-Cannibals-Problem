#ifndef STATE_H
#define STATE_H

#include "SubProblem.h"

using namespace std;

// class which handles that currnet state in the problem 
class State
{
    private:
    StateData leftSide;
    StateData rightSide;
    StateData boat;
    //todo make parent state
        
    public:
    State();
    State(StateData leftSide,StateData rightSide,StateData boatSide);
    ~State();

    //used to update or set the left side of the current state
    void SetLeftSide(StateData leftSide);
    //used to get the current left side of the current state
    StateData getLeftSide();
    //checks if LeftSide is valid
    bool CheckLeftValid();

    //used to update or set the Right side of the current state
    void SetRightSide(StateData RightSide);
    //used to get the current Right side of the current state
    StateData getRightSide();
    //checks if rightSide is valid
    bool CheckRightValid();

    
    //used to update or set the Boat of the current state
    void SetBoat(StateData Boat);
    //used to get the  Boat of the current state
    StateData getBoat();
    // checks if boat is valid
    bool CheckBoatValid();  
};
#endif