#include <iostream>

#define row 12

using namespace std;

int main() {
  char data[2000][100];
  int n = 0;
  while (fgets(data[n], 100, stdin) != NULL) {
    n++;
  }
  //for (int i = 0; i < n; i++) printf("%.*s\n", row, data[i]);

  int left[2000] = {};
  int count = n;
  int target = 0;

  for (int i = 0; i < row; i++) {
    int one = 0;
    int zero = 0;
    for (int j = 0; j < n; j++) {
      if (left[j] != 0) continue; 
      if (data[j][i] == '1') one++;
      else zero++;
    }
    char most = one >= zero ? '1' : '0';
    //char least = one >= zero ? '0' : '1';
    //printf("the most char is %c\n", most);
    for (int j = 0; j < n; j++) {
      if (left[j] != 0) continue;
      if (data[j][i] != most) {
        if (count == 1) {target = j; break;}
        left[j] = -1;
        count--;
      }
      else {
        if (count == 1) {target = j; break;}
      }
    }
    if (count == 1) break;
    //for (int j = 0; j < n; j++) {printf("%d, ", left[j]);}
    //printf("\n");
  }
  //printf("most is %.*s\n", row, data[target]);

  long a = 0;
  for (int i = 0; i < row; i++) {
    if (data[target][i] == '1') a = a * 2 + 1;
    else a = a * 2;
  }

  for (int i = 0; i < n; i++) left[i] = 0;
  count = n;
  target = 0;

  for (int i = 0; i < row; i++) {
    int one = 0;
    int zero = 0;
    for (int j = 0; j < n; j++) {
      if (left[j] != 0) continue; 
      if (data[j][i] == '1') one++;
      else zero++;
    }
    //char most = one >= zero ? '1' : '0';
    char least = one >= zero ? '0' : '1';
    //printf("the least char is %c\n", least);
    for (int j = 0; j < n; j++) {
      if (left[j] != 0) continue;
      if (data[j][i] != least) {
        if (count == 1) {target = j; break;}
        left[j] = -1;
        count--;
      }
      else {
        if (count == 1) {target = j; break;}
      }
    }
    if (count == 1) break;
    //for (int j = 0; j < n; j++) {printf("%d, ", left[j]);}
    //printf("\n");
  }
  //printf("least is %.*s\n", row, data[target]);

  long b = 0;
  for (int i = 0; i < row; i++) {
    if (data[target][i] == '1') b = b * 2 + 1;
    else b = b * 2;
  }

  printf("%ld, %ld, %ld\n", a, b, a*b);
  return 0;
}
