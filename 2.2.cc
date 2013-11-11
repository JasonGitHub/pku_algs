// C-String
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int findMaxIndex(char* str, int n) {
  char max = 0, ix = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] > max) {
      max = str[i];
      ix = i;
    }
  }
  return ix;
}

void insert(char* str, char* substr, int n, int m) {
  int ix = findMaxIndex(str, n);
  for (int i = n - 1; i > ix; --i) {
    str[i + m] = str[i];
  }
  for (int i = ix + 1, j = 0; j < m; ++i, ++j) {
    str[i] = substr[j];
  }
  str[m + n] = '\0';
}

int main() {
  char str[100];
  char substr[100];
  string s1, s2;
  while (cin >> s1 >> s2) {
    strcpy(str, s1.c_str());
    strcpy(substr, s2.c_str());
    insert(str, substr, s1.size(), s2.size());
    cout << str << endl;
  }
  return 0;
}

// STL
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string str, substr;
  while (cin >> str >> substr) {
    int pos = max_element(str.begin(), str.end()) - str.begin();
    str.insert(pos + 1, substr);
    cout << str << endl;
  }
  return 0;
}

