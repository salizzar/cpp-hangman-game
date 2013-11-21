#include <iostream>

#pragma once

class Score {
private:
  int value, penalties;

public:
  Score();

  int   get();
  void  add(int);

  bool  operator <  (Score);
  bool  operator >  (Score);
  bool  operator <= (Score);
  bool  operator >= (Score);
  bool  operator == (Score);
  bool  operator != (Score);
};

