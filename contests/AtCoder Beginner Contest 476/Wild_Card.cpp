#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s,t;

  cin >> n >> s >> t;
  int i = 0, j = 0;
  bool flag = true;
  while(i < n) {
    if(t[j] != '*' && s[i] != t[j]) {
      flag = false;
      break;
    }
    i++;
    j++;
  }

  if(flag) cout << "Yes";
  else cout << "No";
  return 0;

}