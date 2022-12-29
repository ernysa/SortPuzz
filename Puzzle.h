#include <vector>
#include <stack>
#include <string>
#include <map>
#include <iterator>
#include <unordered_set>

using namespace std;
#ifndef SORTPUZZ_PUZZLE_H
#define SORTPUZZ_PUZZLE_H

class Puzzle
{
public:
  // attributes
  vector<stack<string>> grid;
  int numberOfStacks;
  int stackHeight;
  unordered_set<string> visited;
  vector<vector<int>> answerMod;

  // methods
  void addBottle(stack<string> bottle);
<<<<<<< Updated upstream
  bool isValidMove();                                                 // ortak
  string convertGridToString();                                       // mahmut sedat
  bool isSolved();                                                    // mahmut sedat
=======
  bool isValidMove(stack<string>, stack<string>);                     // ortak
  string convertGridToString(vector<stack<string>> grid);             // mahmut sedat
  bool isSolved(vector<stack<string>> grid);                          // mahmut sedat
>>>>>>> Stashed changes
  void transferTo(stack<string> &source, stack<string> &destination); // mahmut sedat
  bool solvePuzzle(vector<stack<string>> grid);                       // ortak
  bool isGridValid();                                                 // eren
};

#endif // SORTPUZZ_PUZZLE_H