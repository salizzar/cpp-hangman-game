#include "ranking.h"

using namespace std;

void Ranking::load(){
  try {
    Player player;
    ifstream file("ranking.dat", ios::binary);

    while (file.read((char*) &player, sizeof(Player)))
      this->players.append(player);

    file.close();
  } catch (exception &e) {
    cout << "\n" << "ranking.dat not found" << "\n";
  }
}

void Ranking::show(){
  Node<Player>* walker = this->players.getHead();
  Player player;

  cout << "\n-------------------------------";
  cout << "\n          HALL OF FAME         ";
  cout << "\n-------------------------------";

  while (walker != NULL){
    player = walker->data;

    cout << "\n";
    cout << setw(30) << player.getLogin();
    cout << setw(20) << player.getScore().get();

    walker = walker->next;
  }
}

bool Ranking::newRecord(Player& player){
  if (this->players.isEmpty())
    return true;

  Node<Player>* walker = this->players.getHead();

  while (walker != NULL && walker->data.getScore() > player.getScore())
    walker = walker->next;

  return walker == NULL || walker->data.getScore() <= player.getScore();
}

void Ranking::update(Player &player){
  this->insert(player);

  this->save();
}

void Ranking::insert(Player &player){
  Node<Player>* walker = this->players.getHead();

  while (walker != NULL && walker->data.getScore() > player.getScore())
    walker = walker->next;

  this->players.insert(walker, player);
}

void Ranking::save(){
  try {
    Node<Player>* walker = this->players.getHead();
    ofstream file("ranking.dat", ios::binary);

    while (walker != NULL){
      file.write((char*) &walker->data, sizeof(Player));
      walker = walker->next;
    }

    file.close();
  } catch (exception &e) {
    cout << "\n" << "Cannot write to ranking.dat, cannot proceed" << "\n";
  }
}

