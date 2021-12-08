#include <iostream>
#include <string>

using namespace std;

#define MAX 100000000

int main() {
  int calls[200];
  int n = 0;
  char line[1000], *p;
  fgets(line, 1000, stdin);
  line[(int)strlen(line)-1] = 0;
  for (p = strtok(line, ","); p; p = strtok(NULL, ",")) {
    calls[n] = stoi(p);
    //printf("%s\n", p);
    n++;
  }
  int bingo[5][5];
  int answer[5][5];
  int lowest = 0;
  int score = 0;
  while (fgets(line, 1000, stdin) != NULL) {
    for (int i = 0; i < 5; i++) {
      fgets(line, 1000, stdin);
      if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
      int j = 0;
      for (p = strtok(line, " "); p; p = strtok(NULL, " ")) {
        bingo[i][j] = stoi(p);
        j++;
      }
    }
    //for (int i = 0; i < 5; i++) {for (int j = 0; j < 5; j++) {printf("%d ", bingo[i][j]);} printf("\n");} printf("\n");
    for (int i = 0; i < 5; i++) {for (int j = 0; j < 5; j++) {answer[i][j] = 0;}}
    int k = 0;
    while (k < n) {
      int curr = calls[k];
      k++;
      int r = -1;
      int c = -1;
      bool found = false;
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          if (bingo[i][j] == curr) {
            found = true;
            answer[i][j] = 1;
            r = i;
            c = j;
            break;
          }
        }
        if (found == true) break;
      }
      if (found == false) continue;
      int row_sum = answer[r][0] + answer[r][1] + answer[r][2] + answer[r][3] + answer[r][4];
      int col_cum = answer[0][c] + answer[1][c] + answer[2][c] + answer[3][c] + answer[4][c];
      int dig_sum = r == c ? answer[0][0] + answer[1][1] + answer[2][2] + answer[3][3] + answer[4][4] : 0;
      if (row_sum == 5 || col_cum == 5 || dig_sum == 5) {
        if (k < lowest) break;
        int marked = bingo[r][c];
        int unmarked = 0;
        for (int i = 0; i < 5; i++) {
          for (int j = 0; j < 5; j++) {
            if (answer[i][j] == 0) unmarked += bingo[i][j];
          }
        }
        lowest = k;
        score = marked * unmarked;
        break;
      }
    }
  }
  printf("%d, %d\n", lowest, score);
  return 0;
}













