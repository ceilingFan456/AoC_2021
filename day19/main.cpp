#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point {
  public:
    int x;
    int y;
    int z;
    Point(int a, int b, int c) {
      x = a;
      y = b; 
      z = c;
    }
};
/*
class Line {
  public:
    Point p;
    Point q; // p -> q or q - p
    int len;
    Line(Point a, Point b) {
      p = a;
      q = b;
      len = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    }
}

bool equal_lines(Line a, Line b) {
  return a.len == b.len;
}
*/

class Line {
  public:
    int start;
    int end;
    int len;

};

int find_len(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

int main() {
  char line[1000];
  vector<vector<Point> > sc_points;
  int n = -1;
  while (fgets(line, 1000, stdin)) {
    if (strncmp(line, "---", 3) == 0) {
      n++;
      vector<Point> cur;
      sc_points.push_back(cur);
      continue;
    }
    if (line[0] == '\n') {
      continue;
    }
    line[(int)strlen(line)-1] = 0;
    char *p;
    p = strtok(line, ",");
    int x = stoi(p);
    p = strtok(NULL, ",");
    int y = stoi(p);
    p = strtok(NULL, ",");
    int z = stoi(p);
    Point cur = Point(x, y, z);
    sc_points[n].push_back(cur);
  }
  /*
  for (int i = 0; i < sc_points.size(); i++) {
    printf("---scanner %d---\n", i);
    for (int j = 0; j < sc_points[i].size(); j++) {
      Point p = sc_points[i][j];
      printf("(%d, %d, %d)\n", p.x, p.y, p.z);
    }
  }
  */

  // a better implementation should use ufds to 
  // start construction from any two scanners
  // because scanner 0 has only 6+6 common points
  // and the method should be faster also
  //
  // here uses a simpler approach and start with
  // scanner 0 and build from there
  
  int visited[39] = {0};
  int total = 1;
  int counts = 0;
  while (total < 39) {
    
  }

  return 0;
}
