#include <iostream>
#include <vector>

using namespace std;

struct Pos {
  int x;
  int y;

  Pos(int x, int y) {
    this->x = x;
    this->y = y;
  }
};
int seq = 1;

void search(vector<vector<int>> &visited, const Pos &p, const Pos &loc,
            int &count) {
  if (count == visited.size() + visited[0].size() - 1) {
    return;
  }
  if (p.x == loc.x && p.y == loc.y) {
    if (count > seq) {
      count = seq;
      return;
    }
  }
  vector<Pos> temp;
  if (p.x + 1 >= 0 && p.y >= 0 && p.x + 1 < visited.size() &&
      p.y < visited[0].size() && visited[p.x + 1][p.y] == 1) {
    temp.push_back(Pos(p.x + 1, p.y));
  }
  if (p.x - 1 >= 0 && p.y >= 0 && p.x - 1 < visited.size() &&
      p.y < visited[0].size() && visited[p.x - 1][p.y] == 1) {
    temp.push_back(Pos(p.x - 1, p.y));
  }
  if (p.x >= 0 && p.y + 1 >= 0 && p.x < visited.size() &&
      p.y + 1 < visited[0].size() && visited[p.x][p.y + 1] == 1) {
    temp.push_back(Pos(p.x, p.y + 1));
  }
  if (p.x >= 0 && p.y - 1 >= 0 && p.x < visited.size() &&
      p.y - 1 < visited[0].size() && visited[p.x][p.y - 1] == 1) {
    temp.push_back(Pos(p.x, p.y - 1));
  }
  visited[p.x][p.y] = 0;
  seq++;
  for (const auto &t : temp) {
    search(visited, t, loc, count);
  }
  visited[p.x][p.y] = 1;
  seq--;
}

int solution(vector<vector<int>> maps) {
  Pos loc = Pos(maps.size() - 1, maps[0].size() - 1);
  int count = maps.size() * maps[0].size() + 1;
  auto start = Pos(0, 0);
  search(maps, start, loc, count);
  if (count == maps.size() * maps[0].size() + 1) {
    return -1;
  } else {
    return count;
  }
}

int main() {
  vector<vector<int>> maps;
  int answer;
  maps = {{1, 1, 1, 1, 1}}; // 11
  answer = solution(maps);
  cout << answer << endl;

  return 0;
}