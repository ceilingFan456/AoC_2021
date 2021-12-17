#include <vector>
#include <iostream>

using namespace std;

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  long long counter = 0;
  int vy = d;
  while (vy < -d+1) {
    int steps = 1;
    vector<int> visited;
    // find possible steps for current vy;
    int dis_y = 0;
    while (true) {
      dis_y += vy - steps + 1;
      if (dis_y > c) { steps++; continue;}
      else if (dis_y < d) break;
      else {
        int vx = 1;
        while (vx <= b) {
          int ivx = vx;
          int dis_x = 0;
          for (int i = 0; ivx > 0 && i < steps; i++) {
            dis_x += ivx;
            ivx--;
          }
          if (dis_x >= a && dis_x <= b) {
            bool found = false;
            for (int i = 0; i < visited.size(); i++) {
              found = found || visited[i] == vx;
            }
            if (!found) {
              counter++;
              visited.push_back(vx);
              cout << "vx is " << vx << " vy is " << vy << endl;
            }
          }
          vx++;
        }
      }
      steps++;
    }
    vy++;
//    for (int i = 0; i < visited.size(); i++) cout << visited[i] << " ";
//    cout << endl;
    visited.clear();
  }
  printf("%lld\n", counter);
  return 0;
}
