#include <iostream>
#include <cstdio>

using namespace std;

#define row 5

int main() {
  char data[2000][100];
  int n = 0;
  int one[row] = {};
  int zero[row] = {};
  while (n < 12) {
    fgets(data[n], 100, stdin);
    //printf("%s\n", data[n]);
    for (int i = 0; i < row; i++) {
      if (data[n][i] == '1') {
        one[i] += 1;
      } 
      else {
        zero[i] += 1;
      }
    }
    n++;
  }
  printf("n=%d\n", n);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < row; i++) {printf("%c", data[j][i]);}
    printf("end of row\n");
  }
  char most[row];
  char least[row];
  for (int i = 0; i < row; i++) {
    if (zero[i] <= one[i]) {
      most[i] = '1';
      least[i] = '0';
    } 
    else {
      most[i] = '0';
      least[i] = '1';
    }
  }
  printf("most is %.*s\n", row, most);
  printf("least is %.*s\n", row, least);
  int high_most = 0;
  int high_least = 0;
  int idx_most = 0;
  int idx_least = 0;
  int score = 0;
  for (int i = 0; i < n; i++) {
    score = 0;
    for (int j = 0; j < row; j++) {
      if (data[i][j] == most[j]) {score++;}
      else break;
    }
    if (score > high_most) {high_most = score; idx_most = i;}
    score = 0;
    for (int j = 0; j < row; j++) {
      if (data[i][j] == least[j]) {score++;}
      else break;
    }
    if (score > high_least) {high_least = score; idx_least = i;}
  }
  long a = 0;
  long b = 0;
  for (int i = 0; i < row; i++) {
    if (data[idx_most][i] == '1') {a = a*2+1;}
    else {a = a*2;}
    if (data[idx_least][i] == '1') {b = b*2+1;}
    else {b = b*2;}
  }
  printf("%ld, %ld\n", a, b);
  printf("%ld\n", a*b);
  return 0;
}
