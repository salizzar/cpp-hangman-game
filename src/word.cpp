#include "word.h"

using namespace std;

Word::Word() : string(NULL) {}

Word::Word(char* word){
  this->string = new char[WORD_SIZE];
  strcpy(this->string, word);
}

char* Word::value(){
  return this->string;
}

int Word::size(){
  return strlen(this->string);
}

int Word::indexof(char letter){
  int pos = -1;
  int i = 0;
  int size = strlen(this->string);

  while (i < size && toupper(letter) != toupper(this->string[i]))
    i++;

  if (i < size)
    pos = i;

  return pos;
}

char Word::charat(int index){
  return this->string[index];
}

bool Word::contains(char letter){
  bool found = false;

  int i = 0;
  int size = strlen(this->string);

  while (!found && i < size){
    found = (toupper(this->string[i]) == toupper(letter));
    i++;
  }

  return found;
}

