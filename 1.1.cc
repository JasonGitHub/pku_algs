// http://dsalgo.openjudge.cn/dsmoochw2/1/
#include <iostream>
#include <map>

using namespace std;

void add(map<int, int> &a, map<int, int> &b) {
  for (map<int, int>::iterator it = b.begin(); it != b.end(); ++it) {
    a[it->first] += it->second;
  }
}

void print(map<int, int> &a) {
  for (map<int, int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
    if (it->second != 0) cout << "[ " << it->second << " " << it->first << " ]" << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    map<int, int> a, b;
    int c, e;
    while (cin >> c >> e && e >= 0) a[e] += c;
    while (cin >> c >> e && e >= 0) b[e] += c;
    add(a, b);
    print(a);
  }
}
