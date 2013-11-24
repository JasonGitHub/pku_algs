// http://dsalgo.openjudge.cn/dsmoochw4/1/
#include <iostream>
#include <string>
#include <map>

using namespace std;

void Solve(string s, char &c, int &cnt) {
  map<char, int> mp;
  for (int i = 0; i < s.size(); ++i) {
    ++mp[tolower(s[i])];
  }
  c = 'a';
  cnt = mp[c];
  for (map<char, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    if (it->second > cnt) {
      c = it->first; 
      cnt = it->second;
    }
  }
}

int main() {
  int n;
  string s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char c;
    int cnt;
    cin >> s;
    Solve(s, c, cnt);
    cout << c << " " << cnt << endl;
  }
  return 0;
}
