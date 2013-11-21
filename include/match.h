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

  int   mark(char);

  char  charat(int);

  int   size();
};

