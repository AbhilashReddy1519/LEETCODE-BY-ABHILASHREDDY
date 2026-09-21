#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  if(str.back() == 'e') cout << str + "r";
  else cout << str + "er";
  return 0;
}