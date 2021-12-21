#include <iostream>

using namespace std;

int main() {
  int score[2] = {0};
  int location[2] = {3, 8};
  int dice = 1;
  int rolls = 0;
  int turn = 0;
  while (true) {
    int steps = 0;
    for (int i = 0; i < 3; i++) {
      rolls += 1;
      steps += dice;
      dice += 1;
      if (dice > 100) dice = dice - 100;
    }
    location[turn] += steps;
    location[turn] = location[turn] % 10;
    score[turn] += location[turn] + 1;

    if (score[0] >= 1000) {
      cout << "player 1 has won" << endl;
      cout << "his score is " << score[0] << "and rolls is " << rolls << endl; 
      cout << rolls * score[1] << endl;
      break;
    }
    else if (score[1] >= 1000) {
      cout << "player 2 has won" << endl;
      cout << "his score is " << score[1] << "and rolls is " << rolls << endl; 
      cout << rolls * score[0] << endl;
      break;
    }
    turn = (turn + 1) % 2;
  }
  return 0;
}
