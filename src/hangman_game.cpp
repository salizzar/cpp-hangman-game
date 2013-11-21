#include "hangman_game.h"

using namespace std;

HangmanGame::HangmanGame(Dictionary &dictionary, Ranking &ranking){
  this->dictionary = dictionary;
  this->ranking = ranking;
  this->logged = false;
}

void HangmanGame::login(){
  char login[12];

  cout << "\n" << "Enter your login: "; cin >> login;

  this->player = Player(login);
  this->logged = true;
}

void HangmanGame::logout(){
  this->logged = false;
}

void HangmanGame::run(){
  if (!this->logged) {
    cout << "\n" << "You must be logged to play.";
    return;
  }

  Word word = this->dictionary.getWord();

  Game game(this->player, word);
  game.play();

  if (this->ranking.newRecord(this->player)) {
    this->ranking.update(this->player);
  }
}

void HangmanGame::showRanking(){
  this->ranking.show();
}

void HangmanGame::manageSettings(){
}

void HangmanGame::exit(){
  this->logged = false;
}

