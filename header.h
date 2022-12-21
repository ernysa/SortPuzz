#include <vector>
#include <stack>
#include <string>
using namespace std;
class bottle
{
    public:
        //attributes
        int bottleHeight;
        stack<string> balls;

        //methods
        int pourOut(){};
        void fill(){};
};
class grid
{
    public:
        //attributes
        vector<bottle> bottles;
        int numberOfStacks;
        int stackHeight;

        //methods
        int getStackHeight(){};
        bool isValidMove(){};
        string gridConvertedtoString(){};
        bool isSolved(){};
        bool solvePuzzle(){};
        bool isGridValid(){};
};