// http://dsalgo.openjudge.cn/dsmoochw3/3/
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n;
    stack<int> st;
    int op, val;
    bool is_stack = true;
    for (int j = 0; j < n; ++j) {
      cin >> op >> val;
      if (op == 1) st.push(val);
      else {
        int top = st.top();
        if (top != val) is_stack = false;
        st.pop();
      }
    }
    if (is_stack) cout << "Stack" << endl;
    else cout << "Queue" << endl;
  }
  return 0;
}
