// http://dsalgo.openjudge.cn/dsmoochw3/2/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

void PrintStack(deque<int> s) {
  for (deque<int>::iterator it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  int m, n;
  cin >> m;
  string op;
  for (int i = 0; i < m; ++i) {
    deque<int> s;
    cin >> n;
    bool err = false;
    for (int j = 0; j < n; ++j) {
      cin >> op;
      if (op == "push") {
        int val;
        cin >> val;
        s.push_back(val);
      } else {
        if (s.empty()) {
          err = true;
        } else s.pop_back();
      }
    }
    if (err) cout << "error" << endl;
    else if (!s.empty()) PrintStack(s);
  }
  return 0;
}
