#include <vector>
#include <stack>
#include <string>
#include <map>
#include <iterator>

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

  // methods
  void addBottle(stack<string> bottle);
  bool isValidMove();                                                 // ortak
  string convertGridToString();                                       // mahmut sedat
  bool isSolved();                                                    // mahmut sedat
  void transferTo(stack<string> &source, stack<string> &destination); // mahmut sedat
  bool solvePuzzle();                                                 // ortak
  bool isGridValid();                                                 // eren
};

#endif // SORTPUZZ_PUZZLE_H