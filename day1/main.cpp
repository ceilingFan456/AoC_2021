#include <stdio.h>
using namespace std;

int main() {
  int a, b, c=0; scanf("%d", &a);
  while (scanf("%d", &b) != EOF) {
    c += a < b ? 1 : 0;
    a = b;
  }
  printf("%d", c);
  return 0;
}
