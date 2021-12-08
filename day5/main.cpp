#include <iostream>

using namespace std;

int main() {
  int map[1000][1000] = {0};
  char line[100] = "";
  while (fgets(line, 100, stdin) != NULL) {
    for (int i = 0; line[i] != 0; i++) {
      if (line[i] == ',') line[i] = ' ';
    }
    char *p;
    int a = stoi(strtok(line, " "));
    int b = stoi(strtok(NULL, " "));
    strtok(NULL, " ");
    int c = stoi(strtok(NULL, " "));
    int d = stoi(strtok(NULL, " "));
    if (a == c) {
      int small = b < d ? b : d;
      int big = b < d ? d : b;
      for (int i = small; i <= big; i++) map[a][i] += 1;
    }
    else if (b == d) {
      int small = a < c ? a : c;
      int big = a < c ? c : a;
      for (int i = small; i <= big; i++) map[i][b] += 1;
    }
    else {
      int x = a < c ? 1 : -1;
      int y = b < d ? 1 : -1;
      while (a != c+x) {
        map[a][b] += 1;
        a += x;
        b += y;
      }
    }
  }
  int counter = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (map[i][j] >= 2) counter++;
    }
  }
  printf("%d\n", counter);
  return 0;
}
