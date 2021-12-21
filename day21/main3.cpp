#include <iostream>

using namespace std;

long long all_universe_a = 0;
long long all_universe_b = 0;

int number_universe[10] = {-1, -1, -1, 1, 3, 6, 7, 6, 3, 1};

void play(int loc_a, int score_a, 
    int loc_b, int score_b, long long universe, int turn) {
  if (turn == 0) {
    for (int i = 3; i < 10; i++) {
      int loc_new = (loc_a + i) % 10;
      long long universe_new = universe * number_universe[i];
      int score_new = score_a + loc_new + 1;
      if (score_new >= 21) {
        all_universe_a += universe_new;
      }
      else {
        play(loc_new, score_new, loc_b, score_b, universe_new, 1);
      }
    }
  }
  else {
    for (int i = 3; i < 10; i++) {
      int loc_new = (loc_b + i) % 10;
      long long universe_new = universe * number_universe[i];
      int score_new = score_b + loc_new + 1;
      if (score_new >= 21) {
        all_universe_b += universe_new;
      }
      else {
        play(loc_a, score_a, loc_new, score_new, universe_new, 0);
      }
    }
  }
}

int main() {
  play(3, 0, 8, 0, 1, 0);
  long long bigger = all_universe_a > all_universe_b ? all_universe_a : all_universe_b;
  cout << bigger << endl;
  return 0;
}
