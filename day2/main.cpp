#include <string>
#include <iostream>

using namespace std;

int main() {
  string op;
  int a;
  long dis = 0;
  long dep = 0;
  long aim = 0;
  while (cin >> op >> a) {
    if (op == "forward") {dis += a; dep += a * aim;} 
    else if (op == "down") {aim += a;}
    else {aim -= a;}
    printf("%ld, %ld, %ld\n", dis, dep, aim);
  }
  printf("%ld\n", dep*dis);
  return 0;
}
