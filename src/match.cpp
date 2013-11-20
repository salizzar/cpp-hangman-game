#include "match.h"

Match::Match(Word &word){
  this->word = word;
  this->initializeBuffer();
}

void Match::initializeBuffer(){
  int size = this->word.size();

  this->buffer = new bool[size];

  for (int i = 0; i < size; i++)
    this->buffer[i] = false;
}

bool Match::already(char letter){
  int pos = this->word.indexof(letter);

  return pos != -1 && this->buffer[pos];
}

bool Match::found(char letter){
  return this->word.contains(letter);
}

void Match::mark(char letter){
  char *word = this->word.value();
  char chr;

  for (int i = 0; i < strlen(word); i++){
    chr = word[i];

    if (toupper(chr) == toupper(letter)){
      this->buffer[i] = true;
    }
  }
}

bool Match::completed(){
  int i = 0;
  int size = this->word.size();

  while (i < size && this->buffer[i])
    i++;

  return i == size;
}

char Match::charat(int index){
  if (index < 0 || index > this->word.size())
    return ' ';

  return (this->buffer[index] ? this->word.charat(index) : ' ');
}

int Match::size(){
  return strlen(this->word.value());
}

