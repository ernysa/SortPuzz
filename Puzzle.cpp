#include "Puzzle.h"
#include <iostream>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void Puzzle::addBottle(stack<string> bottle)
{
  this->grid.push_back(bottle);
}

bool Puzzle::isSolved()
{
  for (auto stack : this->grid)
  {
    vector<string> colors;
    while (!stack.empty())
    {
      colors.push_back(stack.top());
      stack.pop();
    }
    if (!colors.size())
      continue;
    else if (colors.size() < this->stackHeight)
      return false;
    else if (std::count(colors.begin(), colors.end(), colors[0]) != this->stackHeight)
      return false;
  }
  return true;
}

string Puzzle::convertGridToString()
{
  string finalString;
  for (auto stack : this->grid)
  {
    string colors;
    while (!stack.empty())
    {
      colors.insert(0, stack.top());
      stack.pop();
    }

    finalString += (colors + ";");
  }
  return finalString;
}
void Puzzle::transferTo(stack<string> &source, stack<string> &destination)
{
  int bottleSize = this->stackHeight;

  stack<string> toBeMoved;
  string first = source.top();
  toBeMoved.push(first);
  source.pop();

  while (toBeMoved.top() == source.top())
  {
    toBeMoved.push(source.top());
    source.pop();
  };
  while (!toBeMoved.empty())
  {
    if (destination.size() < bottleSize)
    {
      destination.push(toBeMoved.top());
    }
    else
    {
      source.push(toBeMoved.top());
    }
    toBeMoved.pop();
  }
}

// todo: arrange the cpp files later.
bool Puzzle::isGridValid()
{
  int expectedNumberOfBalls = (this->numberOfStacks - 2) * (this->stackHeight);
  int numberOfBalls = 0;

  // count the total number of balls
  for (auto i : grid)
  {
    numberOfBalls += i.size();
  }
  if (numberOfBalls != expectedNumberOfBalls)
  {
    cout << "Number of balls isn't what it should be!" << endl;
    return false;
  }
  // count the number of each different colored ball
  map<string, int> balls;
  vector<stack<string>> newGrid = grid;
  for (auto tube : newGrid)
  {
    while (!tube.empty())
    {
      string key = tube.top();
      tube.pop();
      balls[key] += 1;
    }
  }
  // checking if the grid has the right amount of ball of each color
  map<string, int>::iterator it = balls.begin();
  while (it != balls.end())
  {
    if (it->second != stackHeight)
    {
      cout << "There aren't " << stackHeight << " balls of color " << it->first << endl;
      return false;
    }
    it++;
  }
  return true;
}

bool Puzzle::isValidMove(stack <string> sourceStack, stack <string> destinationStack){
  if (sourceStack.size() == 0 || destinationStack.size() == this->stackHeight)
    return false;
  stack <string> comparisonStack = sourceStack;
  string topColor = comparisonStack.top();
  int ballsOfSameColor = 0;
  for(int i= 0; i < comparisonStack.size();i++){  //finds the number of same colored balls in the source stack
    if (comparisonStack.top() == topColor){
      ballsOfSameColor++;
    }
  }
  if(ballsOfSameColor == this->stackHeight) //if all of the balls are same colored in the source stack
    return false;                           //don't touch it

  if (destinationStack.size() == 0){
    if(ballsOfSameColor == sourceStack.size())  //destination stack is empty but source stack
      return false;                             //has only same colored balls, don't touch it
    return true;
  }
  
  return sourceStack.top() == destinationStack.top();
}