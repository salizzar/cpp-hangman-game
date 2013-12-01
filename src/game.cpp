#include "game.h"

using namespace std;

Game::Game(Player &player, Word &word){
  this->player = &player;
  this->word = word;
}

void Game::play(){
  int tries = 0;
  bool over = false;
  char letter;

  Match match(this->word);

  Renderer renderer;
  renderer.render(tries, MAX_TRIES, match);

  Score& score = this->player->getScore();
  int points;

  do {
    cout << "\n" << "Digit a letter: "; cin >> letter;
    cout << "\n";

    if (match.already(letter)){
      cout << "\n" << "Already found, try again";
      continue;
    }

    if (match.found(letter)){
      points = match.mark(letter);
      score.add(points);
    } else {
      tries++;
    }

    renderer.render(tries, MAX_TRIES, match);

    over = match.completed() || tries == MAX_TRIES;
  } while (!over);

  if (tries == MAX_TRIES){
    cout << "\n" << "YOU LOSE! :(";
  } else {
    cout << "\n" << "YOU WIN! :D";
  }
}

