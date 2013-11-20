#include <iostream>

#pragma once

class Score {
private:
  int value, penalties;

public:
  Score();

  int   get();
  void  add(int);
};

