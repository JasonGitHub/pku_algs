#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>
#include <map>
#include <string>
#include <limits>

// Assume the expression is correctly formed

using namespace std;

static int Pre(char op) {
  map<char, int> precedence = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
  return precedence[op];
}

template <typename T>
string ToRPE(string expr) {
  stringstream in(expr);
  string rpe;
  stack<char> ops;
  char op;
  while (in >> op) {
    if (!isdigit(op)) {
      switch (op) {
        case '(': ops.push(op); break;
        case ')': while (ops.top() != '(') {
                    rpe = rpe + ops.top() + " ";
                    ops.pop();
                  }
                  ops.pop();
                  break;
        case '+': case '-': case '*': case '/':
                  while (!ops.empty() && ops.top() != '(' && Pre(op) <= Pre(ops.top())) {
                    ops.pop();
                  }
                  ops.push(op);
                  break;
        default: ;
      }
    } else {
      in.putback(op);
      T val;
      in >> val;
      rpe = rpe + to_string(val) + " ";
    }
  }
  while (!ops.empty()) {
    rpe = rpe + ops.top() + " ";
    ops.pop();
  }
  return rpe;
}

template <typename T>
void GetTwoOperands(stack<T> &s, T &v1, T &v2) {
  v1 = s.top();
  s.pop();
  v2 = s.top();
  s.pop();
}

template <typename T>
void Compute(stack<T> &s, char op) {
  T v1, v2;
  GetTwoOperands(s, v1, v2);
  switch (op) {
    case '+': s.push(v2 + v1); break;
    case '-': s.push(v2 - v1); break;
    case '*': s.push(v2 * v1); break;
    case '/': s.push(v2 / v1); break;
  }
}

template <typename T>
T Eval(string expr) {
  stringstream in(expr);
  stack<T> s;
  char op;
  while (in >> op) {
    switch(op) {
      case '+': case '-': case '*': case '/': Compute(s, op); break;
      default:
        in.putback(op);
        T v;
        in >> v;
        s.push(v);
        break;
    }
  }
  return s.top();
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for (int i = 0; i < n; ++i) {
    string expr;
    getline(cin, expr);
    cout << Eval<int>(ToRPE<int>(expr)) << endl;
  }
  return 0;
}
