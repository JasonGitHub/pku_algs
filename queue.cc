template <class T>
class Queue {
public:
  void clear();
  bool enQueue(const T item);
  bool deQueue(T &item);
  bool getFront(T &item);
  bool isEmpty();
  bool isFull();
};

// Based on Array "circular buffer"
template <class T> 
class Aqueue: public Queue<T> {
private:
  int size;
  int front;
  int rear;
  T *listArray;
public:
  AQueue(int sz = DefaultListSize) {
    size = sz + 1;
    rear = 0;
    front = 1;
    listArray = new T[size];
  }
  ~AQueue() {
    delete[] listArray;
  }
  void clear() {
    front = rear + 1;
  }
  bool enqueue(const T& it) {
    if (((rear + 2) % size) == front) return false;
    rear = (rear + 1) % size;
    listArray[rear] = it;
    return true;
  }
  bool dequeue(T& it) {
    if (length() == 0) return false;
    it = listArray[front];
    front = (front + 1) % size;
    return true;
  }
  bool frontValue(T& it) const {
    if (length() == 0) return false;
    it = listArray[front];
  }
  int length() const {
    return (size + (rear - front + 1)) % size;
  }
}

// Based on Linked List
template <class T>
class lnkQueue: public Queue<T> {
private:
  int size;
  Link<T>* front;
  Link<T>* rear;
public:
  lnkQueue(int size)
  ~lnkQueue();
  
  bool enqueue(const T item) {
    if (rear == NULL) {
      front = rear = new Link<T> (item, NULL);
    } else {
      rear->next = new Link<T> (item, NULL);
      rear = rear->next;
    }
    ++size;
    return true;
  }

  bool dequeue(T* item) {
    Link<T>* tmp;
    if (size == 0) {
      cout << "empty queue" << endl;
      return false;
    }
    *item = front->data;
    tmp = front;
    front = front->next;
    delete tmp;
    if (front == NULL) rear = NULL;
    --size;
    return true;
  }
}
