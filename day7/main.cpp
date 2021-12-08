#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 0;
  char line[10000];
  fgets(line, 10000, stdin);
  char *p;
  int arr[10000];
  for (p = strtok(line, ","); p; p = strtok(NULL, ",")) {
    int a = stoi(p);
    arr[n] = a;
    n += 1;
  }
  //sort(arr, arr+n);
  long pre = INT_MAX;
  long cur = INT_MAX - 1;
  int x = 0;
  for (x = 0; cur < pre; x++) {
    pre = cur;
    cur = 0;
    for (int i = 0; i < n; i++) {
      int dif = arr[i] - x > 0 ? arr[i] - x : x - arr[i];
      cur += dif * (dif + 1) / 2;
    }
  }
  printf("%ld", pre);
  return 0;
}
