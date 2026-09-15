#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void build(const vector<vector<int>> &dungeons, unordered_set<int> &visited,
           int k, int length, int &max) {
  for (int i = 0; i < dungeons.size(); i++) {
    if (visited.find(i) == visited.end()) {
      auto &d = dungeons[i];
      if (k >= d[0]) {
        unordered_set<int> new_visited = visited;
        new_visited.insert(i);
        build(dungeons, new_visited, k - d[1], length + 1, max);
      }
    }
  }
  if (length > max) {
    max = length;
  }
}

int solution(int k, vector<vector<int>> dungeons) {
  unordered_set<int> visited;
  int length = 0;
  int max = 0;
  build(dungeons, visited, k, length, max);

  return max;
}

int main() {
  int k = 0;
  vector<vector<int>> dungeons;

  k = 80;
  dungeons = {{80, 20}, {50, 40}, {30, 10}};
  int max = solution(k, dungeons);
  cout << max << endl;
  return 0;
}