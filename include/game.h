#include <iostream>
#include "player.h"
#include "word.h"
#include "match.h"
#include "renderer.h"

#pragma once

const int MAX_TRIES = 7;

class Game {
private:
  Player  player;
  Word    word;

public:
  Game(Player&, Word&);

  void play();
};

