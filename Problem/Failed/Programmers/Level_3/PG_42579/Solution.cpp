#include <bits/stdc++.h>

using namespace std;

// # Prototype Declaration ====================
int solution(vector<vector<int>> targets);
// # Global Variable & Constant================

// # Implements Definition ====================
// ## Main
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<vector<int>> input;

  {
    string rawInput;
    string buffer;
    regex regExp("[0-9]+");

    freopen(".example\\Programmers\\question\\input.txt", "rt", stdin);
    getline(cin, rawInput);

    sregex_token_iterator iter(
      rawInput.begin(),
      rawInput.end(),
      regExp
    ), end;

    while(iter != end) {
      vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
      input.push_back(tempVec);
    }
  }

  cout << solution(input) << '\n';
  return 0;
}

// ## Solution
int solution(vector<vector<int>> targets) {
  int answer = -1;

  for(vector<int> target : targets) {
    cout << "[" << target[0] << ", " << target[1] << "]\n";
  }

  return answer;
}