#include "util.h"

using namespace std;

void Util::clearInputBuffer(){
   if (cin.fail()){
     char dummy[255];
     cin.clear();
     cin >> dummy;
   }
}

