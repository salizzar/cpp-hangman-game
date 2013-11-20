#include "hangman_game.h"

using namespace std;

HangmanGame::HangmanGame(Dictionary &dictionary, Ranking &ranking){
  this->dictionary = dictionary;
  this->ranking = ranking;
  this->logged = false;
}

void HangmanGame::login(){
  this->player = Player::authenticate();
  this->logged = true;
}

void HangmanGame::run(){
  if (!this->logged) {
    cout << "\n" << "You must be logged to play.";
    return;
  }

  Word word = this->dictionary.getWord();

  Game game(player, word);
  game.play();

/*
  if (this->ranking.newRecord(player)) {
    this->ranking.update(player);
  }
*/
}

void HangmanGame::showRanking(){
}

void HangmanGame::manageSettings(){
}

void HangmanGame::exit(){
  this->logged = false;
}

