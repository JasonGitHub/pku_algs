// http://dsalgo.openjudge.cn/dsmoochw4/2/
#include <iostream>
#include <cctype>

using namespace std;

string Decrept(string msg) {
  for (int i = 0; i < msg.size(); ++i) {
    if(isalpha(msg[i])) msg[i] = (msg[i] - 'A' + 21) % 26 + 'A';
  }
  return msg;
}

int main() {
  string msg, word;
  while (cin >> word && word != "ENDOFINPUT") {
    if (word == "START") msg.clear();
    else if (word == "END") cout << Decrept(msg) << endl;
    else msg = msg + word + " ";
  }
  return 0;
}
