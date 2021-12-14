#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<char> base;
  
  char line[1000];
  fgets(line, 1000, stdin);
  line[(int)strlen(line)-1] = 0;
  for (int i = 0; i < (int)strlen(line); i++) {
    base.push_back(line[i]);
  }

  fgets(line, 1000, stdin);

  char table[26][26];
  long long pre[26][26][26];
  long long cur[26][26][26];

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      table[i][j] = 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        pre[i][j][k] = 0;
        cur[i][j][k] = 0;
      }
    }
  }

  while (fgets(line, 1000, stdin)) {
    char a = line[0];
    char b = line[1];
    char c = line[6];
    //pre[a-'A'][b-'A'][c-'A'] = 1;
    table[a-'A'][b-'A'] = c;
  }

  int layers = 40;
  while (layers--) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (table[i][j] == 0) continue;
        int l = table[i][j] - 'A';
        for (int k = 0; k < 26; k++) {
          cur[i][j][k] = pre[i][l][k] + pre[l][j][k];
        }
        cur[i][j][l] += 1;
      }
    }
    //printf("============current layer is %d\n", layers);
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
          //if (cur[i][j][k] != 0) printf("%c-%c  %c %lld\n", i+'A', j+'A', k+'A', cur[i][j][k]);
          pre[i][j][k] = cur[i][j][k];
        }
      }
    }
  }

  long long count[26] = {0};
  char a, b;
  for (int i = 0; i < base.size()-1; i++) {
    a = base[i];
    b = base[i+1];
    for (int j = 0; j < 26; j++) {
      count[j] += cur[a-'A'][b-'A'][j];
    }
    count[a-'A'] += 1;
  }
  count[b-'A'] += 1;

  long long min = LLONG_MAX;
  long long max = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] == 0) continue;
    if (min > count[i]) min = count[i];
    if (max < count[i]) max = count[i];
  }

  printf("%lld, %lld, %lld\n", max, min, max-min);
  return 0;
}
