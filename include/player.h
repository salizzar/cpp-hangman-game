#include <iostream>
#include <stdio.h>
#include <string.h>
#include "score.h"
#include "util.h"

#pragma once

class Player {
private:
  char* login;
  Score score;

public:
  Player();
  Player(char*);

  Score getScore();
  char* getLogin();
};

