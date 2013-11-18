template <class T>
class Stack {
public:
  void clear();
  bool push(const T item);
  bool pop(T& item);
  bool top(T& item);
  bool isEmpty();
  bool isFull();
};

// Based on Array
template <class T>
class arrStack : public Stack<T> {
private:
  int mSize;
  int top;
  T *st;
public:
  arrStack(int size) {
    mSize = size;
    top = -1;
    st = new T[mSize];
  }
  arrStack() {
    top = -1;
  }
  ~arrStack() {
    delete[] st;
  }
  void clear() {
    top = -1;
  }
  bool arrStack<T>::push(const T item) {
    if (top == mSize - 1) {
      cout << "stack is full" << endl;
      return false;
    } else {
      st[++top] = item;
      return true;
    }
  }
  bool arrStack<T>::pop(T &item) {
    if (top == -1) {
      cout << "empty stack" << endl;
      return false;
    } else {
      item = st[top--];
      return false;
    }
  }
};

// Based on Linked List
template <class T>
class lnkStack : public Stack<T> {
private:
  Link<T>* top;
  int size;
public:
  lnkStack(int defSize) {
    top = NULL;
    size = 0;
  }
  ~lnkStack() {
    clear();
  }
  bool push(const T item) {
    Link<T>* tmp = new Link<T>(item, top);
    top = tmp;
    ++size;
    return true;
  }
  bool pop(T& item) {
    Link<T>* tmp;
    if (size == 0) {
      cout << "empty stack" << endl;
      return false;
    }
    item = top->data;
    tmp = top->next;
    delete top;
    top = tmp;
    --size;
    return true;
  }
};
