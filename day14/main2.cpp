#include <iostream>
#include <stack>

using namespace std;

int main() {
  //stack<pair<int, char> > s;
  int stack[100][2];
  int s = 0;
  char table[26][26];
  for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) table[i][j] = 0;
  int layer = 40;
  long long count[26] = {0};
  
  char line[1000];
  fgets(line, 1000, stdin);
  line[(int)strlen(line)-1] = 0;
  //for (int i = (int)strlen(line)-1; i >= 0; i--) s.push(make_pair(0, line[i]));
  for (int i = (int)strlen(line)-1; i >= 0; i--) {
    stack[s][0] = 0;
    stack[s][1] = line[i];
    s++;
  }
/*
  stack<pair<int, char> > helper;
  while (!s.empty()) {
    helper.push(s.top());
    s.pop();
  }
  while (!helper.empty()) {
    pair<int, char> tmp = helper.top(); helper.pop();
    printf("(%d, %c) ", tmp.first, tmp.second);
    s.push(tmp);
  }
  printf("\n");
*/
  fgets(line, 1000, stdin);

  while (fgets(line, 1000, stdin)) {
    char a = line[0];
    char b = line[1];
    char c = line[6];
    table[a-'A'][b-'A'] = c;
//    printf("%c %c -> %c\n", a, b, c);
  }

//  for (int i = 0; i < 26; i++) { for (int j = 0; j < 26; j++) {printf("%c", table[i][j]);}printf("\n");}

  while (s != 0) {
    /*
    pair<int, char> cur = s.top(); s.pop();
    int a = cur.first;
    char b = cur.second;
    */
    s--;
    int a = stack[s][0];
    char b = stack[s][1];
    count[b-'A'] += 1;
//    printf("%c", b);
    for (int i = a+1; i <= layer; i++) {
      //if (s.empty()) break;
      if (s == 0) break;
      //char c = s.top().second;
      char c = stack[s-1][1];
      if (table[b-'A'][c-'A'] == 0) break;
      char d = table[b-'A'][c-'A'];
      //s.push(make_pair(i, d));
      stack[s][0] = i;
      stack[s][1] = d;
      s++;
    }
  }
  long long min = LLONG_MAX;
  long long max = 0;
  for (int i = 0; i < 26; i++) {
    if (count[i] == 0) continue;
    if (count[i] > max) max = count[i];
    if (count[i] < min) min = count[i];
  }
  printf("%lld, %lld, %lld\n", max, min, max-min);
  return 0;
}
