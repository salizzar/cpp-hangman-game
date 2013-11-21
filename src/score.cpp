#include "score.h"

using namespace std;

Score::Score() : value(0) {}

int Score::get(){
  return this->value;
}

void Score::add(int points){
  this->value += points;
}

bool Score::operator <  (Score other){
  return this->value <  other.get();
}

bool Score::operator >  (Score other){
  return this->value >  other.get();
}

bool Score::operator <= (Score other){
  return this->value <= other.get();
}

bool Score::operator >= (Score other){
  return this->value >= other.get();
}

bool Score::operator == (Score other){
  return this->value == other.get();
}

bool Score::operator != (Score other){
  return this->value != other.get();
}

