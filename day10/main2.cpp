#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  char line[1000];
  vector<long long> sum;
  int n = 0;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    stack<char> s;
    char *p = line;
    bool flag = true;
    while (*p != 0) {
      if (*p == '(' || *p == '[' || *p == '{' || *p == '<') s.push(*p);
      else if (!s.empty()){
        char a = s.top();
        if ((*p == ')' && a == '(') || (*p == ']' && a == '[') 
            || (*p == '}' && a == '{') || (*p == '>' && a == '<')) s.pop();
        else {
          flag = false;
          break;
        }
      }
      else {
        flag = false;
        break;
      }
      p++;
    }
    long long cur = 0;
    while (!s.empty()) {
      char a = s.top();
      s.pop();
      int b = 0;
      if (a == '(') b = 1;
      else if (a == '[') b = 2;
      else if (a == '{') b = 3;
      else b = 4;
      cur = cur * 5 + b;
    }
    if (flag) {
      sum.push_back(cur);
      n++;
    }
  }
  sort(sum.begin(), sum.end());
  printf("%lld\n", sum[n/2]);
}
