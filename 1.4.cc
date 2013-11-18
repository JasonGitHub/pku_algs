// http://dsalgo.openjudge.cn/dsmoochw2/4/
#include <iostream>

using namespace std;

// m: num of apples n: num of plates
int f(int m,int n) {
  if (m == 0 || n == 1)
    return 1;
  else if (m < 0 || n <= 0)
    return 0;
  else
    return f(m, n - 1) + f(m - n, n); // case 0: at least one plate left empty case 1: no plates are left empty
}

int main() {
  int t, m, n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> m >> n;
    cout << f(m, n) << endl;
  }
} 
