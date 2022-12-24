#include <vector>
#include <stack>
#include <string>
using namespace std;

class Puzzle
{
public:
    // attributes
    vector<stack<string>> grid;
    int numberOfStacks;
    int stackHeight;

    // methods
    void addBottle(stack<string> bottle){
        grid.push_back(bottle);
    }
    int getStackHeight(){};                                           // mahmut sedat
    bool isValidMove(){};                                             // ortak
    string gridConvertedtoString(){};                                 // mahmut sedat
    bool isSolved(){};                                                // mahmut sedat
    void transferTo(stack<string> source, stack<string> destination){}; // mahmut sedat
    bool solvePuzzle(){};                                             // ortak
    bool isGridValid();                                             // eren
};
