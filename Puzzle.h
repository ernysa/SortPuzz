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
  vector<stack<string>> initGrid;
  int numberOfStacks;
  int stackHeight;
  unordered_set<string> visited;
  vector<vector<int>> answerMod;

  // methods
  void addBottle(stack<string> bottle);
  bool isValidMove(stack<string>, stack<string>);
  string convertGridToString(vector<stack<string>> grid);
  bool isSolved(vector<stack<string>> grid);
  void transferTo(stack<string> &source, stack<string> &destination);
  bool solvePuzzle(vector<stack<string>> grid);
  bool isGridValid();
  void printAnswer();
};

#endif // SORTPUZZ_PUZZLE_H