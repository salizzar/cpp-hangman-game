#include "dictionary.h"

using namespace std;

void Dictionary::load(){
  try {
    ifstream file("words.txt");
    char line[WORD_SIZE];

    while (file.getline(line, WORD_SIZE)) {
      Word word = this->parse(line);
      this->words.append(word);
    }

    file.close();
  } catch(exception &e) {
    cout << "\n" << "words.txt not found" << "\n";
  }
}

Word Dictionary::getWord(){
  int index = this->getRandom(this->words.getSize());

  Word *words = this->words.values();

  return words[index];
}

int Dictionary::getRandom(int size){
  srand(time(NULL));

  return rand() % size;
}

Word Dictionary::parse(char* line){
  return Word(line);
}
