#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void search(int start, vector<bool> &visited, const vector<vector<int>> &wires,
            int &count) {
  const auto &a = wires[start][0];
  const auto &b = wires[start][1];
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      const auto &wire = wires[i];
      if (wire[0] == a || wire[1] == a || wire[0] == b || wire[1] == b) {

        visited[i] = 1;
        count++;
        search(i, visited, wires, count);
      }
    }
  }
}

int solution(int n, vector<vector<int>> wires) {
  int min = n;
  for (int i = 0; i < wires.size(); i++) {
    int count = 2;
    vector<bool> visited(wires.size());
    visited[i] = 1;
    if (i == 0) {
      visited[1] = 1;
      search(1, visited, wires, count);
    } else {
      visited[0] = 1;
      search(0, visited, wires, count);
    }
    int val = abs(n - 2 * count);
    if (val < min) {
      min = val;
    }
  }
  return min;
}

int main() {
  int n = 0;
  vector<vector<int>> wires;

  n = 9;
  wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};

  int answer = solution(n, wires);

  cout << endl;
  cout << answer;

  return 0;
}