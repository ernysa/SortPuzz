#include "Puzzle.h"

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