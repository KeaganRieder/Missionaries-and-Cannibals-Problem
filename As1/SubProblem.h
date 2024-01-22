// struct which holds the values of missionaries and cannibals
// for each sub section of a state, Ie left,right sides or current
// boat
struct StateData
{
    public:
    int missionaries;
    int cannibals;
};

// // enum used as a key to deterimin what to check
// enum SubProblem{
//     LeftSide = 0,
//     Boat = 1,
//     RightSide = 2,
// };
