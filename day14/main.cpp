#include <iostream>

using namespace std;

int main() {
  char line[1000];
  fgets(line, 1000, stdin);
  line[(int)strlen(line)-1] = 0;
  long n = (int)strlen(line);
  char cur[1000000];
  char pre[1000000];
  for (int i = 0; i < n; i++) {
    pre[i] = line[i];
  }
  int table[26][26];
  for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) table[i][j] = -1;
  fgets(line, 1000, stdin);
  while (fgets(line, 1000, stdin)) {
    int a = line[0] - 'A';
    int b = line[1] - 'A';
    table[a][b] = line[6];
  }

  int k = 10;
  long long i, j;
  char *p, *q;
  p = pre;
  q = cur;
  while (k--) {
    j = 0;
    for (i = 0; i < n-1; i++) {
      int a = *(p+i);
      int b = *(p+i+1);
      int c = table[a-'A'][b-'A'];
      if (c != -1) {
        *(q+j++) = a;
        *(q+j++) = c;
      } else {
        *(q+j++) = a;
      }
    }
    *(q+j++) = *(p+n-1);
    char *tmp;
    tmp = p;
    p = q;
    q = tmp;
    n = j;
//    for (i = 0; i < n; i++) printf("%c", *(p+i));
//    printf("\n");
  }
  long long counts[26] = {0};
  for (i = 0; i < n; i++) {
    char d = *(p+i);
    counts[d-'A'] += 1;
  }
  long long min = INT_MAX;
  long long max = 0;
  for (i = 0; i < 26; i++) {
    if (counts[i] == 0) continue;
    if (counts[i] < min) min = counts[i];
    if (counts[i] > max) max = counts[i];
  }
  printf("%lld, %lld, %lld\n", max, min, max - min);
  return 0;
}
