#include <iostream>
#include <queue>

using namespace std;

#define size 10


int main() {
  char line[1000];
  int arr[size][size];
  int i = 0;
  int j;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    char *p;
    j = 0;
    for (p = line; *p != 0; p++) {
      arr[i][j++] = *p - '0';
    }
    i++;
  }
  //for (i = 0; i < size; i++) {for (j = 0; j < size; j++) {printf("%d", arr[i][j]);} printf("\n");}
  int n = 0;
  long long sum = 0;
  while (1) {
    n++;
    queue<pair<int, int> > q;
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (arr[i][j] == 9) q.push(make_pair(i, j));
        arr[i][j] += 1;
      }
    }
    while(!q.empty()) {
      pair<int, int> a = q.front();
      q.pop();
      for (i = a.first-1; i <= a.first+1; i++) {
        for (j = a.second-1; j <= a.second+1; j++) {
          if (i < 0 || j < 0 || i >= size || j >= size) continue;
          if (arr[i][j] > 9) continue;
          else if (arr[i][j] == 9) {
            q.push(make_pair(i, j));
            arr[i][j] += 1;
          }
          else arr[i][j] += 1;
        } 
      }
    }
    int count = 0;
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (arr[i][j] == 10) {
          arr[i][j] = 0;
          count++;
        }
      }
    }
    if (count == 100) break;
  }
  printf("%d\n", n);
  return 0;
}
