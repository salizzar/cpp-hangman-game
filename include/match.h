#include <iostream>
#include <stdlib.h>
#include "word.h"

#pragma once

class Match {
private:
  Word  word;
  bool  *buffer;

  void initializeBuffer();

public:
  Match(Word&);

  bool  already(char);
  bool  found(char);
  bool  completed();
  bool  marked(int);

  void  mark(char);

  char  charat(int);

  int   size();
};

