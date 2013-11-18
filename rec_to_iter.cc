// Instruction for labels setting in "recursion" to "iteration" conversion
// 1. label 0: first executable line
// 2. label t + 1: end of the recursive function
// 3. label i (1 <= i <= t): the returning point of ith recursion call
// (t: number of recursions)

// Rec
void exmp(int n, int &f) {
  int u1, u2;
  if (n < 2) f = n + 1;
  else {
    exmp((int)(n / 2), u1);
    exmp((int)(n / 4), u2);
    f = u1 * u2;
  }
}

// Iter Data Structure
typedef struct T {
  int rd, pn, pf, q1, q2;
} T;

class nonrec {
private:
  stack<T> s;
public:
  nonrec() {}
  void replace1(int n, int &f);
};

// Iter
void nonrec::replace1(int n, int &f) {
  T x, tmp;
  x.rd = 3;   // label t + 1
  x.pn = n;
  s.push(x);  // push to the bottom of the stack, as sentinel

label0: 
  if ((x = s.top()).pn < 2) {  // base case
    s.pop();
    x.pf = x.pn + 1;
    s.push(x);
    goto label 3;
  }
  
  x.rd = 1;  // first recursion call 
  x.pn = (int)(x.pn / 2); // passing arguments
  s.push(x);
  goto label0; // go to its base case

label1:
  tmp = s.top(); s.pop();
  x = s.top(); s.pop();
  x.q1 = tmp.pf;
  s.push(x);
  
  x.rd = 2;  // second recursion call
  x.pn = (int)(x.pn / 4);  // passing arguments 
  s.push(x);
  goto label0;  // go to its base case

label2:
  tmp = s.top(); s.pop();
  x = s.top(); s.pop();
  x.q2 = tmp.pf;
  x.pf = x.q1 * x.q2;
  s.push(x);

label3:   // return (exit) handling
  x = s.top();
  switch(x.rd) {
    case 1: goto label1; break;  // return to ith label, and 
    case 2: goto label2; break;
    case 3: tmp = s.top();
            s.pop();
            f = tmp.pf;
            break;
    default: cerr << "invalid label number" << endl; break;
  }
}

// Optimized
void nonrec::replace2(int n, int &f) {
  T x, tmp;
  x.rd = 3; x.pn = n; s.push(x);
  do {
    while ((x = s.top()).pn >= 2) {
      x.rd = 1;
      x.pn = (int)(x.pn / 2);
      s.push(x);
    }
    x = s.top();
    s.pop();
    x.pf = x.pn + 1;
    s.push(x);
    while ((x = s.top()).rd == 2) {
      tmp = s.top();
      s.pop();
      x = s.top();
      s.pop();
      x.pf = x.q * tmp.pf;
      s.push(x);
    }
    if ((x = s.top()).rd == 1) {
      tmp = s.top();
      s.pop();
      x = s.top();
      s.pop();
      x.q = tmp.pf;
      s.push(x);
      tmp.rd = 2;  // second recursion call
      tmp.pn = (int)(x.pn / 4);
      s.push(tmp);
    }
  } while ((x = s.top()).rd != 3);
  x = s.top();
  s.pop();
  f = x.pf;
}
