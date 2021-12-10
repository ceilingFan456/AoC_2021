#include <iostream>
#include <stack>

using namespace std;

int main() {
  char line[1000];
  long sum = 0;
  while (fgets(line, 1000, stdin)) {
    if (line[(int)strlen(line)-1] == '\n') line[(int)strlen(line)-1] = 0;
    stack<char> s;
    char *p = line;
    while (*p != 0) {
      if (*p == '(' || *p == '[' || *p == '{' || *p == '<') s.push(*p);
      else if (!s.empty()){
        char a = s.top();
        if ((*p == ')' && a == '(') || (*p == ']' && a == '[') 
            || (*p == '}' && a == '{') || (*p == '>' && a == '<')) s.pop();
        else {
          if (*p == ')') sum += 3;
          else if (*p == ']') sum += 57;
          else if (*p == '}') sum += 1197;
          else sum += 25137;
          break;
        }
      }
      else {
        printf("%c\n", *p);
        if (*p == ')') sum += 3;
        else if (*p == ']') sum += 57;
        else if (*p == '}') sum += 1197;
        else sum += 25137;
        break;
      }
      p++;
    }
    while (!s.empty()) s.pop();
  }
  printf("%ld", sum);
}
