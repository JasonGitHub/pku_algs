void hanoi(int n, char X, char Y, char Z) {
  if (n <= 1)
    move(X, Z)
  else {
    hanoi(n - 1, X, Z, Y);
    move(X, Z);
    hanoi(n - 1, Y, X, Z);
  }
}

void move(char X, char Y) {
  cout << "move" << X << "to" << Y << endl;
}
