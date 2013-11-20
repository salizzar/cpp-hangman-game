#include <iostream>
#include "dictionary.h"
#include "ranking.h"
#include "player.h"
#include "word.h"
#include "game.h"

#pragma once

class HangmanGame {
private:
  bool        logged;
  Player      player;
  Dictionary  dictionary;
  Ranking     ranking;

  void showMenu();

public:
  HangmanGame(Dictionary&, Ranking&);

  void login();
  void run();
  void showRanking();
  void manageSettings();
  void exit();
};

