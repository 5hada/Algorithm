#include <cmath>
#include <iostream>
#include <string>

using namespace std;
// 6진수인데 0은 뒷자리로부터 연속으로만 존재할 수 있다는 규칙
int solution(string word) {
  string seq = "AEIOU";
  string temp;
  for (int i = 0; i < 5; i++) {
    if (word.length() > i) {
      for (int j = 0; j < 5; j++) {
        if (word[i] == seq[j]) {
          temp += to_string(j + 1);
          break;
        }
      }
    } else {

      temp += '0';
    }
  }
  //   cout << temp << endl;
  int input = stoi(temp);
  int count = 1;
  int num = 10000;
  string t;
  while (num < input) {
    t = to_string(num);
    if (t.find('0') != t.npos) {
      num += pow(10, (5 - 1 - t.find('0')));
    } else {
      num++;
      t = to_string(num);
      while (t.find('6') != t.npos) {
        int i = t.find('6');
        t[i] = '0';
        t[i - 1] = (char)t[i - 1] + 1;
        num = stoi(t);
      }
    }
    count++;
    // cout << num << ' ';
  }
  return count;
}

int main() {
  string word = "AAAAE"; // 6
  int answer = solution(word);
  cout << endl;
  cout << answer << endl;

  word = "AAAE"; // 10
  answer = solution(word);
  cout << endl;
  cout << answer << endl;

  word = "I"; // 1563
  answer = solution(word);
  cout << endl;
  cout << answer << endl;

  return 0;
}