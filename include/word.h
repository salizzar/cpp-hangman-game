#include <iostream>
#include <stdio.h>
#include <string.h>

#pragma once

const int WORD_SIZE = 255;

class Word {
private:
  char *string;

public:
  Word();
  Word(char*);

  char* value();
  int   size();
  int   indexof(char);
  char  charat(int);
  bool  contains(char);
};

