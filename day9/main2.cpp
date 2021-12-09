#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  char line[1000];
  char map[1000][1000];
  int visited[1000][1000];
  for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) {map[i][j] = '9'; visited[i][j] = 1;}
  int r = 1, c = 1;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    for (c = 1; line[c-1] != 0; c++) {
      map[r][c] = line[c-1];
      if (map[r][c] != '9') visited[r][c] = 0;
    }
    r++;
  }
  queue<pair<int, int> > list;
  vector<int> basins;
  int colour = 2;
  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if (visited[i][j] != 0) continue;
      int size = 0;
      list.push(make_pair(i, j));
      while (!list.empty()) {
        pair<int, int> cur = list.front();
        list.pop();
        int a = cur.first;
        int b = cur.second;
        if (visited[a][b] != 0) continue;
        size++;
        visited[a][b] = colour;
        if (visited[a-1][b] == 0) list.push(make_pair(a-1, b)); 
        if (visited[a+1][b] == 0) list.push(make_pair(a+1, b)); 
        if (visited[a][b-1] == 0) list.push(make_pair(a, b-1)); 
        if (visited[a][b+1] == 0) list.push(make_pair(a, b+1)); 
      }
      colour++;
      basins.push_back(size);
    }
  }
  sort(basins.begin(), basins.end());
  long product = basins.back();
  basins.pop_back();
  product *= basins.back();
  basins.pop_back();
  product *= basins.back();
  printf("%ld\n", product);
  return 0;
}
