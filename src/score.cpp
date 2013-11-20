#include "score.h"

Score::Score() : value(0) {}

int Score::get(){
  return this->value;
}

void Score::add(int points){
  this->value += points;
}

