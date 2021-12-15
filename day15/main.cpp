#include <iostream>
#include <queue>
#define size 10

using namespace std;

/*
class tuple {
  public:
    int dis;
    int x;
    int y;
    tuple(int a, int b, int c) {
      dis = a;
      x = b;
      y = c;
    }
}

class tuple_comparator {
  public:
    bool operator()(tuple& t1, tuple& t2) {
      if (t1.dis < t2.dis) return true;
      return false;
    }
}

tuple make_tuple(int x, int y, int z) {
  tuple t(x, y, z);
  return t;
}

*/
int main() {
  int arr[size][size];
  int visited[size][size];
  long long dp[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr[i][j] = 0;
      visited[i][j] = 0; 
      dp[i][j] = 0;
    }
  }
  char line[1000];
  int n = 0;
  while(fgets(line, 1000, stdin)) {
    line[(int)strlen(line)-1] = 0;
    for (int i = 0; i < size; i++) {
      arr[n][i] = line[i]-'0';
    }
    n++;
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
/*
  priority_queue<tuple, vector<tuple>, tuple_comparator > queue;
  queue.push(make_tuple(0, 0, 0));

  while (1) {
    tuple tri = queue.top(); queue.pop();
    int dis = tri.dis;
    int x = tri.x;
    int y = tri.y;
    if (visited[x][y] != 0) continue;

    dp[x][y] = dis;
    visited[x][y] = 1;

    if (x == size-1 && y == size-1) break;

    if (x-1>=0 && x-1 < size && visited[x-1][y] == 0) queue.push(make_tuple(dis + arr[x-1][y], x-1, y));  
    if (x+1>=0 && x+1 < size && visited[x+1][y] == 0) queue.push(make_tuple(dis + arr[x+1][y], x+1, y));  
    if (y-1>=0 && y-1 < size && visited[x][y-1] == 0) queue.push(make_tuple(dis + arr[x][y-1], x, y-1));  
    if (y+1>=0 && y+1 < size && visited[x][y+1] == 0) queue.push(make_tuple(dis + arr[x][y+1], x, y+1));  
  }
  
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%lld ", dp[i][j]);
    }
    printf("\n");
  }

  printf("%lld\n", dp[size-1][size-1]);
*/
  return 0;
}
