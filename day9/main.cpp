#include <iostream>

using namespace std;

int main() {
  char line[1000];
  char map[1000][1000];
  for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) map[i][j] = '9' + 1;
  int r = 1, c = 1;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    for (c = 1; line[c-1] != 0; c++) {
      map[r][c] = line[c-1];
    }
    r++;
  }
  long sum = 0;
  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      char a = map[i][j];
      char l = map[i][j-1];
      char r = map[i][j+1];
      char u = map[i-1][j];
      char d = map[i+1][j];
      if (a < l && a < r && a < u && a < d) sum += a - '0' + 1;
    }
  }
  printf("%ld\n", sum);
  return 0;
}
