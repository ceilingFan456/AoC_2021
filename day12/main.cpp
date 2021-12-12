#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

int cave[1000][1000];
int visited[1000]; // 0 is never visit before, 1 is visiting
int size[1000] = {0}; // 0 is small, 1 is big
unordered_map<string, int> names;
string rev[1000];
int n = 0;
int ways = 0;
stack<string> s;
stack<string> other;
int flag = -1;

void dfs(int curr, int end) {
  if (curr == end) {
    ways++;
    /*
    while(!s.empty()) {
      string a = s.top(); s.pop();
      other.push(a);
    }
    while (!other.empty()) {
      string a = other.top(); other.pop();
      cout << a << " ";
      s.push(a);
    }
    cout << "end" << endl;
    */
    return;
  }
  if (visited[curr] == 1 && flag != -1) {return;}
  if (visited[curr] == 1 && flag == -1) {flag = curr;}
  if (size[curr] == 0) visited[curr] = 1;
  s.push(rev[curr]);
  for (int i = 0; i < n; i++) {
    if (cave[curr][i] == 1 && rev[i] != "start") {
      dfs(i, end);
    }
  }
  if (size[curr] == 0) {
    if (flag == curr) flag = -1;
    else visited[curr] = 0;
  }
  s.pop();
}

int main() {
  char line[1000];
  char *p, *q;
  for (int i = 0; i < 1000; i++) {for (int j = 0; j < 1000; j++) {cave[i][j] = 0;} visited[i] = 0;}

  while(fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line) - 1] == '\n') line[(int)strlen(line) - 1] = 0;
    p = strtok(line, "-");
    q = strtok(NULL, "-");
    int a = 0;
    int b = 0;
    if (names.find(p) != names.end()) a = names[p];
    else {
      a = n++; 
      names[p] = a;
      rev[a] = p;
      if (*p <= 'Z' && 'A' <= *p) {size[a] = 1;}
    }
    if (names.find(q) != names.end()) b = names[q];
    else {
      b = n++; 
      names[q] = b;
      rev[b] = q;
      if (*q <= 'Z' && 'A' <= *q) {size[b] = 1;}
    }
    cave[a][b] = 1;
    cave[b][a] = 1;
  }
  int start = names["start"];
  int end = names["end"];

  dfs(start, end);

  printf("%d\n", ways);
  return 0;
}
