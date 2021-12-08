#include <iostream>

using namespace std;

int main() {
  int day = 256;
  int cycle = 9;
  long dp[9] = {};
  char line[1000];
  fgets(line, 1000, stdin);
  char *p;
  for (p = strtok(line, ","); p; p = strtok(NULL, ",")) {
    int a = stoi(p);
    dp[a] += 1;
  }
  for (int i = 0; i < day; i++) {
    long a = dp[0];
    for (int i = 0; i < cycle-1; i++) {
      dp[i] = dp[i+1];
    }
    dp[6] += a;
    dp[8] = a;
  }
  long sum = 0;
  for (int i = 0; i < cycle; i++) {
    sum += dp[i];
  }
  cout << sum << endl;
  return 0;
}
