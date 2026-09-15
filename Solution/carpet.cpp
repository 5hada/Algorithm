#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<pair<int, int>> probs;
  for (int i = yellow; i >= sqrt(yellow); i--) {
    if (yellow % i == 0) {
      cout << i << yellow / i << endl;
      probs.push_back({i, yellow / i});
    }
  }
  for (const auto &p : probs) {
    if ((p.first + p.second) * 2 + 4 == brown) {
      return {p.first + 2, p.second + 2};
    }
  }
}

int main() {
  int brown = 0;
  int yellow = 0;

  cin >> brown >> yellow;

  int row = 0, col = 0;
  vector<int> v = solution(brown, yellow);
  cout << v[0] << ", " << v[1] << endl;

  return 0;
}