#include <iostream>
#include <stdio.h>
#include <string.h>
#include "score.h"
#include "util.h"

#pragma once

const int LOGIN_SIZE = 12;

class Player {
private:
  char  login[LOGIN_SIZE];
  Score score;

public:
  Player();
  Player(char*);

  Score getScore();
  char* getLogin();
};

