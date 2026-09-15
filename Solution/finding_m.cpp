#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void build(const string &nums, unordered_set<int> &h, unordered_set<int> &used,
           string n) {
  if (used.size() < nums.length()) {
    for (int i = 0; i < nums.length(); i++) {
      if (used.find(i) == used.end()) {
        string t = n + nums[i];
        h.insert(stoi(t));
        unordered_set<int> new_used = used;
        new_used.insert(i);
        build(nums, h, new_used, t);
      }
    }
  }
}

int solution(string numbers) {
  unordered_set<int> sets;
  unordered_set<int> used;
  string n;
  build(numbers, sets, used, n);
  int num = 0;
  for (const auto &h : sets) {
    cout << h << endl;
    if (h > 1) {
      num++;
    }
    if (h != 2) {
      for (int i = 2; i < sqrt(h); i++) {
        if (h % i == 0) {
          num--;
          break;
        }
      }
    }
  }
  return num;
}

int main() {
  string input = "0017";
  //   cin >> input;
  int num;
  num = solution(input);
  cout << num << endl;

  return 0;
}