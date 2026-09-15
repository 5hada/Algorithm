#include <iostream>
#include <vector>

using namespace std;

void re(int index, const vector<int> &numbers, const int &target, int num,
        int &count) {
  if (index < numbers.size() - 1) {
    re(index + 1, numbers, target, num + numbers[index], count);
    re(index + 1, numbers, target, num - numbers[index], count);
  } else {
    if (num + numbers[index] == target) {
      count++;
    }
    if (num - numbers[index] == target) {
      count++;
    }
  }
}

int solution(vector<int> numbers, int target) {
  int count = 0;
  re(1, numbers, target, numbers[0], count);
  re(1, numbers, target, -numbers[0], count);

  return count;
}

int main() {
  vector<int> numbers;
  int target = 0;
  int answer;

  numbers = {1, 1, 1, 1, 1};
  target = 3;
  answer = solution(numbers, target);

  cout << answer << endl;

  return 0;
}