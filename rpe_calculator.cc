class Calculator {
private:
  stack<T> s;
  bool GetTwoOperands(T &v1, T &v2) {
    if (s.empty()) {
      cerr << "missing operand" << endl;
      return false;
    }
    v1 = s.top();
    s.pop();
    if (s.empty()) {
      cerr << "missing operand" << endl;
      return false;
    }
    v2 = s.pop();
    s.pop();
    return true;
  }
  void Compute(char op) {
    bool result;
    T v1, v2;
    result = GetTwoOperands(v1, v2);
    if (result == true) {
      switch (op) {
        case '+': s.push(v2 + v1); break;
        case '-': s.push(v2 - v1); break;
        case '*': s.push(v2 * v1); break;
        case '/': if (v1 == 0) {
                    cerr << "divide by 0" << endl;
                    stack<T> empty;
                    swap(s, empty);
                  } else {
                    s.push(v2 / v1);
                  }
                  break;
      }
    } else {
      stack<T> empty;
      swap(s, empty);
    }
  }
public:
  Calculator() {};
  void Run() {
    char c;
    T v;
    while (cin >> c, c != '=') {
      switch(c) {
        case '+': case '-': case '*': case '/': Compute(c); break;
        default:
          cin.putback(c); // if it is not an operator, put it back
          cin >> v; // and retrieve it again as an operand
          s.push(v);
          break;
      }
    }
    if (!s.empty()) {
      cout << s.top() << endl;
      s.pop();
    }
  }
  void Clear();
};
