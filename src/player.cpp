#include "player.h"

using namespace std;

Player::Player(){
  this->login = NULL;
}

Player::Player(char* login){
  strcpy(this->login, login);
}

Player Player::authenticate(){
  char login[12];
  cout << "\n" << "Enter your login: "; cin >> login;

  Player player(login);
  return player;
}

