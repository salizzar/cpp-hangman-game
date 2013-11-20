#include "renderer.h"

using namespace std;

void Renderer::render(int tries, int limit, Match &match){
  this->showPuppet(tries, limit);
  this->showMatches(match);
}

void Renderer::showPuppet(int tries, int limit){
  cout << "\n" << "---------------";
  cout << "\n" << "|      |";
  cout << "\n" << "|      |";

  cout << "\n" << "|     ";
  if (tries == limit)
    cout << " |o";

  cout << "\n" << "|     ";
  if (tries >= limit - 3)
    cout << "/";
  if (tries >= limit - 2)
    cout << "|";
  if (tries >= limit - 1)
    cout << "\\";

  cout << "\n" << "|     ";
  if (tries >= limit - 4)
    cout << " |";

  cout << "\n" << "|     ";
  if (tries >= limit - 6)
    cout << "/";
  if (tries >= limit - 5)
    cout << " \\";

  cout << "\n" << "|";
}

void Renderer::showMatches(Match &match){
  cout << "\n" << "|";

  for (int i = 0; i < match.size(); i++){
    char letter = match.charat(i);
    cout << " " << (letter == ' ' ? '_' : letter);
  }

  cout << "\n" << "---------------";
  cout << "\n";
}

