#include <iostream>
#include <fstream>
#include "player.h"
#include "list.h"

#pragma once

class Ranking {
private:
  List<Player> players;

  void insert(Player&);
  void save();

public:
  void  load();
  void  show();

  bool  newRecord(Player&);
  void  update(Player&);
};

