#include "player.h"

using namespace std;

Player::Player(){}

Player::Player(char* login){
  strcpy(this->login, login);
}

Score Player::getScore(){
  return this->score;
}

char* Player::getLogin(){
  return this->login;
}

