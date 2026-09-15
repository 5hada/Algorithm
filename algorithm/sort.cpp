#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(0);
  sort(v.begin(), v.end());

  cout << v[0] << endl;

  return 0;
}