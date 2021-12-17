#include <iostream>
#include <queue>

using namespace std;

int main() {
  char line[2000];
  fgets(line, 2000, stdin);
  line[(int)strlen(line)-1] = 0;
  int n = (int)strlen(line);
  printf("%d\n", n);
  queue<int> src;
  for (int i = 0; i < n; i++) {
    int a = 0;
    if ('0' <= line[i] && line[i] <= '9') a = line[i] - '0';
    else a = line[i] - 'A' + 10;
    int b = 0;
    int n = 4;
    while (n--) {
      b = b * 2 + a % 2;
      a = a / 2;
    }
    src.push(b);
    printf("%d ", b);
  }
  printf("\n");
  int bits = 0;
  int sum = 0;

  int sum_ver = 0;
  
  int m = 2;
  while (m--) {
    while (bits < 6) {
      int a = src.front(); src.pop();
      sum = sum + (a << bits);
      bits += 4;
      cout << "sum is " << sum << endl;
    }

    int ver = sum % 8;
    sum = sum / 8;
    sum_ver += ver;

    int type = sum % 8;
    sum = sum / 8;

    cout<< "type is " << type << endl;

    if (type == 1) {
      int val;
      do {
        while (bits < 5) {
          int a = src.front(); src.pop();
          sum = sum + (a << bits);
          bits += 4;
        }
        val = sum % 32;
        sum = sum / 32;
      } while (val % 2 != 0);
      break;
    }

    else {
      while (bits < 1) {
        int a = src.front(); src.pop();
        sum = sum + (a << bits);
        bits += 4;
      }
      int l = sum % 2;
      sum = sum / 2;
      if (l == 0) {
        while (bits < 15) {
          int a = src.front(); src.pop();
          sum = sum + (a << bits);
          bits += 4;
        }
        int field = 0;
      } 
      else {

      }
    } 
  }
  printf("%d", sum_ver);
  return 0;
}
