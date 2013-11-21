#include "main.h"

using namespace std;

void showMenu(){
  cout << "\n" << "-------------------------------";
  cout << "\n" << "--------- HANGMAN GAME --------";
  cout << "\n" << "-------------------------------";
  cout << "\n" << LOGIN     << " - Login";
  cout << "\n" << LOGOUT    << " - Logout";
  cout << "\n" << PLAY      << " - Play Game";
  cout << "\n" << RANKING   << " - Show Ranking";
  cout << "\n" << SETTINGS  << " - Manage Settings";
  cout << "\n" << EXIT      << " - Exit Program";
  cout << "\n" << "-------------------------------";
  cout << "\n";
  cout << "\n" << "Enter a option: ";
}

int main(){
  int option;

  Dictionary dictionary;
  dictionary.load();

  Ranking ranking;
  ranking.load();

  HangmanGame game(dictionary, ranking);

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option) {
      case LOGIN:
        game.login();
        break;

      case LOGOUT:
        game.logout();
        break;

      case PLAY:
        game.run();
        break;

      case RANKING:
        game.showRanking();
        break;

      case SETTINGS:
        game.manageSettings();
        break;

      case EXIT:
        game.exit();
        break;

      default:
        Util::clearInputBuffer();
        cout << "\n" << "Invalid option, try again";
    }

    cout << "\n";
  } while (option != EXIT);

  return 0;
}

