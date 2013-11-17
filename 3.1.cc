#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>

using namespace std;

void PrintQueue(deque<pair<char, int> > q) {
  for (deque<pair<char, int> >::iterator it = q.begin(); it != q.end(); ++it) {
    cout << it->first << it->second << " ";
  }
}

int main() {
  char c;
  int n, num;
  vector<deque<pair<char, int> > > q1(9);
  vector<deque<pair<char, int> > > q2(4);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c >> num;
    q1[num - 1].push_back(make_pair(c, num));
  }
  for (int i = 0; i < 9; ++i) {
    cout << "Queue" << i + 1 << ":";
    PrintQueue(q1[i]);
    cout << endl;
  }
  for (int i = 0; i < 9; ++i) {
    while (!q1[i].empty()) {
      pair<char, int> p = q1[i].front();
      q2[p.first - 'A'].push_back(p);
      q1[i].pop_front();
    }
  }
  for (int i = 0; i < 4; ++i) {
    cout << "Queue" << static_cast<char>('A' + i) << ":";
    PrintQueue(q2[i]);
    cout << endl;
  }
  for (int i = 0; i < 4; ++i) {
    while (!q2[i].empty()) {
      pair<char, int> p = q2[i].front();
      cout << p.first << p.second << " ";
      q2[i].pop_front();
    }
  }
  cout << endl;
  return 0;
}
