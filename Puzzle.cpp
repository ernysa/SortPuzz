#include "Puzzle.h"

void Puzzle::addBottle(stack<string> bottle)
{
  this->grid.push_back(bottle);
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
  while (toBeMoved.size() != 0)
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