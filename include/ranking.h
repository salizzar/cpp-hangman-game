#include <iostream>
#include "player.h"

#pragma once

class Ranking {
public:
  void load();

  bool  newRecord(Player);
  void  update(Player);
};

