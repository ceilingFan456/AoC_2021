#include <iostream>

using namespace std;

int main() {
  char line[13]; // 12
  int one[12] = {};
  int zero[12] = {};
  while (cin >> line) {
    for (int i = 0; i < 12; i++) {
      if (line[i] == '0') {
        zero[i] += 1;
      }
      else {
        one[i] += 1;
      }
    }
  }
  /*
  char gamma[13] = {};
  char epsilon[13] = {};
  for (int i = 0; i < 12; i++) {
    if (zero[i] > one[i]) {
      gamma[i] = '0';
      epsilon[i] = '1';
    }
    else {
      gamma[i] = '1';
      epsilon[i] = '0';
    }
  }
  */

  long gamma = 0;
  long epsilon = 0;

  for (int i = 0; i < 12; i++) {
    if (zero[i] > one[i]) {
      gamma = gamma * 2 + 0;
      epsilon = epsilon * 2 + 1;
    }
    else {
      gamma = gamma * 2 + 1;
      epsilon = epsilon * 2 + 0;
    }
  }
  printf("%ld, %ld, %ld\n", gamma, epsilon, gamma * epsilon);
  return 0;
}
