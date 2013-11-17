// http://dsalgo.openjudge.cn/dsmoochw2/3/
#include <iostream>
#include <algorithm>

using namespace std;

void Print(unsigned short* arr, int n) {
  for_each(arr, arr + n, [](int x){cout << x << " ";});
  // for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int m, n;
  unsigned short arr[100000 + 10];
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  char c;
  int val;
  for (int i = 0; i < m; ++i) {
    cin >> c >> val;
    if (c == 'C') {
      std::for_each(arr, arr + n, [=](unsigned short &x){x += val;});
      // for (int j = 0; j < n; ++j) arr[j] += val;
    } else {
      int cnt = 0;
      std::for_each(arr, arr + n, [&](unsigned short x){if (x >> val & 1) ++cnt;});
      // for (int j = 0; j < n; ++j) if (arr[j] >> val & 1) ++cnt;
      cout << cnt << endl;
    }
  }
  return 0;
}
