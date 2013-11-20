#include <iostream>
#include <fstream>
#include <cstdlib>
#include "list.h"
#include "word.h"

#pragma once

class Dictionary {
private:
  List<Word> words;

  Word  parse(char*);
  int   getRandom(int);

public:
  void load();

  Word getWord();
};

