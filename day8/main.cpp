#include <iostream>

using namespace std;

bool contains(char *a, char *b) {
  // check if a contains b == if all char in b are in a
  bool all = true;
  while (*b != 0) {
    char c = *b;
    b++;
    bool one = false;
    char *d = a;
    while (*d != 0) {
      one = one || (*d == c);
      d++;
    }
    all = all && one;
  }
  return all;
}

int main2() {
  char a[] = "abcde";
  char b[] = "dc";
  int c = contains(a, b) ? 1 : 0;
  int d = contains(b, a) ? 1 : 0;
  printf("c = %d, d = %d", c, d);
  return 0;
}

int main() {
  char* table[10];
  char* answer[10];
  char* code[4];
  char line[1000];
  char* p;
  bool flag = false;
  int i, j;
  long count = 0;
  while (fgets(line, 1000, stdin)) {
    line[(int)strlen(line) - 1] = 0;
    flag = false;
    i = 0;
    j = 0;
    for (p = strtok(line, " "); p; p = strtok(NULL, " ")) {
      if (!strcmp(p, "|")) {flag = true; continue;}
      if (!flag) {
        table[i++] = p;
      } 
      else {
        code[j++] = p;
      }
    }
    for (int k = 0; k < i; k++) {
      int s = strlen(table[k]);
      if (s == 2) answer[1] = table[k];
      else if (s == 4) answer[4] = table[k];
      else if (s == 3) answer[7] = table[k];
      else if (s == 7) answer[8] = table[k];
    }
    for (int k = 0; k < i; k++) {
      if ((int)strlen(table[k]) != 6) continue;
      if (contains(table[k], answer[4])) answer[9] = table[k];
      else if (contains(table[k], answer[7])) answer[0] = table[k];
      else answer[6] = table[k];
    }
    for (int k = 0; k < i; k++) {
      if ((int)strlen(table[k]) != 5) continue;
      if (contains(table[k], answer[7])) answer[3] = table[k];
      else if (contains(answer[6], table[k])) answer[5] = table[k];
      else answer[2] = table[k];
    }
    printf("%d, %d\n", i, j);
    int cur = 0;
    for (int k = 0; k < j; k++) {
      for (int h = 0; h < i; h++) {
        if (contains(code[k], answer[h]) && contains(answer[h], code[k])) {
          cur = cur * 10 + h;
        }
      }
    }
    count += cur;
    /*
    for (int k = 0; k < j; k++) {
      int s = strlen(code[k]);
      if (s == 2 || s == 4 || s == 3 || s == 7) {
        count++;
//        printf("%s\n", code[k]);
      }
    }
    */
  }
  printf("%ld\n", count);
  return 0;
}
