#include <iostream>
#include <vector>

using namespace std;

void read_number(char *p, vector<pair<int, int> > &lst) {
  int layer = -1;
  while (*p != 0) {
    if (*p == '[') layer++;
    else if (*p == ']') layer--;
    else if (*p >= '0' && *p <= '9') {
      lst.push_back(make_pair(layer, *p-'0'));
    }
    p++;
  }
}

int calculate(char *p, char *q) {
  vector<pair<int, int> > pre;
  vector<pair<int, int> > cur; // <layer, value>
  read_number(p, pre);
  read_number(q, cur); 
  for (int i = 0; i < pre.size(); i++) {
    pair<int, int> a = make_pair(pre[i].first+1, pre[i].second);
    pre[i] = a;
  }
  for (int i = 0; i < cur.size(); i++) {
    pair<int, int> a = make_pair(cur[i].first+1, cur[i].second);
    pre.push_back(a);
  }
  bool reduced = true;
  while(reduced) {
    reduced = false;
    for (int i = 0; i < pre.size(); i++) {
      if (pre[i].first >= 4) { // i is the left element
        reduced = true;
        if (i > 0) {
          pair<int, int> front = make_pair(pre[i-1].first, pre[i-1].second+pre[i].second);
          pre[i-1] = front;
        }
        if (i+1 < pre.size()-1) {
          pair<int, int> back = make_pair(pre[i+2].first, pre[i+2].second+pre[i+1].second);
          pre[i+2] = back;
        }
        pair<int, int> middle = make_pair(pre[i].first-1, 0);
        pre.erase(pre.begin()+i);
        pre[i] = middle;
      }
    }
    for (int i = 0; i < pre.size(); i++) {
      if (pre[i].second > 9) {
        reduced = true;
        int a = pre[i].second;
        int small = a / 2;
        int big = a % 2 == 1 ? a / 2 + 1 : a / 2;
        int l = pre[i].first;
        pre.erase(pre.begin()+i);
        pre.insert(pre.begin()+i, make_pair(l+1, big));
        pre.insert(pre.begin()+i, make_pair(l+1, small));
        break;
      }
    }
  }
  while (pre.size() > 1) {
    for (int i = 0; i < pre.size()-1; i++) {
      if (pre[i].first == pre[i+1].first) {
        int l = pre[i].first - 1;
        int value = pre[i].second * 3 + pre[i+1].second * 2;
        pre.erase(pre.begin()+i);
        pre.erase(pre.begin()+i);
        pre.insert(pre.begin()+i, make_pair(l, value));
        break;
      }
    }
  }
  return pre[0].second;
}

int main() {
  char line[1000];
  char lst[200][200];
  int n = 0;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    char *p = line;
    int m = 0;
    while (*p != 0) {
      lst[n][m] = *p;
      p++;
      m++;
    }
    n++;
  }
  int biggest = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int cur = calculate(lst[i],lst[j]);
      if (cur > biggest) biggest = cur;
    }
  }
  cout << biggest << endl;
  return 0;
}
