#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Solve(string s, char &c, int &cnt) {
  int a[26];
  fill(a, a + 26, 0); 
  for (int i = 0; i < s.size(); ++i) {
    ++a[tolower(s[i]) - 'a'];
  }
  c = 'a';
  cnt = a[0];
  for (int i = 0; i < 26; ++i) {
    if (a[i] > cnt) {
      c = 'a' + i;
      cnt = a[i];
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
