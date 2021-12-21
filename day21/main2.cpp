#include <iostream>

using namespace std;

long long universe_a = 0;
long long universe_b = 0;

void play(int loc_a, int score_a, int loc_b, int score_b, int turn, int steps) {
  if (turn == 0) {
    if (steps > 0) {
      for (int i = 1; i < 4; i++) {
        int loc_new = (loc_a + i) % 10;
        play(loc_new, score_a, loc_b, score_b, 0, steps-1);
      }
    } 
    else {
      int score_new = score_a;
      score_new += loc_a + 1;
      if (score_new >= 21) {
        universe_a++;
      } 
      else {
        play(loc_a, score_new, loc_b, score_b, 1, 3);
      }
    } 
  }
  else {
    if (steps > 0) {
      for (int i = 1; i < 4; i++) {
        int loc_new = (loc_b + i) % 10;
        play(loc_a, score_a, loc_new, score_b, 1, steps-1);
      }
    } 
    else {
      int score_new = score_b;
      score_new += loc_b + 1;
      if (score_new >= 21) {
        universe_b++;
      } 
      else {
        play(loc_a, score_a, loc_b, score_new, 0, 3);
      }
    } 
  }
}

int main() {
  play(3,0, 8, 0, 0, 3);
  long long bigger = universe_a > universe_b ? universe_a : universe_b;
  cout << bigger << endl;
  return 0;
}
