// http://dsalgo.openjudge.cn/dsmoochw4/3/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Sig(const string &s) {
  vector<int> sig(26);
  for (int i = 0; i < s.size(); ++i) {
    ++sig[s[i] - 'A'];
  }
  sort(sig.begin(), sig.end());
  return sig;
}

bool Check(const string &scrt, const string &msg) {
  return Sig(msg) == Sig(scrt);
}

int main() {
  string scrt, msg;
  while (cin >> scrt >> msg) {
    if (Check(scrt, msg)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
