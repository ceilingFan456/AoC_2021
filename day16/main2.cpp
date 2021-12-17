#include <iostream>
#include <queue>

using namespace std;

queue<int> src;
int bits = 0;
int sum = 0;
int sum_ver = 0;

void until_bits(int n) {
  while (bits < n) {
    int a = src.front(); src.pop();
    sum = sum + (a << bits);
    bits += 4;
  }
}

int return_bits(int n) {
  until_bits(n);
  int a = 0;
  for (int i = 0; i < n; i++) {
    a = a * 2 + sum % 2;
    sum = sum / 2;
    bits--;
  }
  return a;
}

pair<int,long long> unpack() {
  int version = return_bits(3);
  sum_ver += version;
  int type_id = return_bits(3);
  int bits_consumed = 6;

  if (type_id == 4) {
    int cur = 0;
    long long value = 0;
    do {
      cur = return_bits(5);
      bits_consumed += 5;
      int a = cur > 15 ? cur - 16 : cur;
      value = (value << 4) + a;
    } while(cur > 15); // 11111 - 10000 continue

    return make_pair(bits_consumed, value);
  } 


  int length_type = return_bits(1);
  bits_consumed += 1;
  queue<long long> values;

  if (length_type == 0) {
    int total_length = return_bits(15);
    bits_consumed += 15;
    int counter = 0;
    while (counter < total_length) {
      pair<int, long long> cur_pair = unpack();
      int cur = cur_pair.first;
      values.push(cur_pair.second);
      counter += cur;
      bits_consumed += cur;
    }
  }
  else { // length_type == 1
    int total_packets = return_bits(11);
    bits_consumed += 11;
    for (int i = 0; i < total_packets; i++) {
      pair<int, long long> cur_pair = unpack();
      int cur = cur_pair.first;
      values.push(cur_pair.second);
      bits_consumed += cur;
    }
  }

  long long value = 0; 
  if (type_id == 0) {
    value = 0;
    while (!values.empty()) {
      value += values.front(); values.pop();
    }
  }
  else if (type_id == 1) {
    value = 1;
    while (!values.empty()) {
      value *= values.front(); values.pop();
    }
  }
  else if (type_id == 2) {
    value = LLONG_MAX;
    while (!values.empty()) {
      value = value > values.front() ? values.front() : value;
      values.pop();
    }
  }
  else if (type_id == 3) {
    value = -1;
    while (!values.empty()) {
      value = value < values.front() ? values.front() : value;
      values.pop();
    }
  }
  else if (type_id == 5) {
    long long a = values.front(); values.pop();
    long long b = values.front(); values.pop();
    value = a > b ? 1 : 0;
  }
  else if (type_id == 6) {
    long long a = values.front(); values.pop();
    long long b = values.front(); values.pop();
    value = a < b ? 1 : 0;
  }
  else if (type_id == 7) {
    long long a = values.front(); values.pop();
    long long b = values.front(); values.pop();
    value = a == b ? 1 : 0;
  }
  return make_pair(bits_consumed, value);
}

int main() {
  char line[2000];
  fgets(line, 2000, stdin);
  line[(int)strlen(line)-1] = 0;
  char *p = line;
  while (*p != 0) {
    int a;
    if (*p >= '0' && *p <= '9') a = *p - '0';
    else a = *p - 'A' + 10;
    int b = 0;
    for (int i = 0; i < 4; i++) {
      b = 2 * b + a % 2;
      a = a / 2;
    }
    src.push(b);
    p++;
  }
  long long value = unpack().second;
  cout << value << endl;
  return 0;
}
