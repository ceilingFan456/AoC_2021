#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int> > v;
  char line[1000];
  vector<pair<int, int> > op;
  int dp[1000][1000]; 
  for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) dp[i][j] = 0;
  int count = 0;
  char *p, *q;

  while (fgets(line, 1000, stdin)) {
    if (strcmp(line, "\n") == 0) break;
    if (line[(int)strlen(line) - 1] == '\n') line[(int)strlen(line)-1] = 0;
    p = strtok(line, ",");
    q = strtok(NULL, ",");
    v.push_back(make_pair(stoi(p), stoi(q)));
  }

  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line) - 1] == '\n') line[(int)strlen(line)-1] = 0;
    int a = line[11] == 'x' ? 1 : 0;
//    printf("%d\n", a);
    strtok(line, "=");
    int b = stoi(strtok(NULL, "="));
//    printf("%d\n", b);
    op.push_back(make_pair(a, b));
  }

  for (auto i = v.begin(); i != v.end(); i++) {
    int a = i->first;
    int b = i->second;
    for (auto j = op.begin(); j != op.end(); j++) {
      int c = j->first;
      int d = j->second;
      if (c == 1 && d < a) a = 2 * d - a;
      if (c == 0 && d < b) b = 2 * d - b;
    }
    if (dp[b][a] == 0) {dp[b][a] = 1; count++;} 
  }
  printf("%d\n", count);
  for (int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if (dp[i][j] == 1) {
        printf("#");
      }
      else printf(" ");
    }
    printf("\n");
  }

  return 0;
}
