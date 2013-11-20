#include <iostream>
#include "match.h"

#pragma once

class Renderer {
private:
  void showPuppet(int, int);
  void showMatches(Match&);

public:
  void render(int, int, Match&);
};

