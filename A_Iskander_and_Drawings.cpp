#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int mx = 0;
    for (char ch : s) {
      if (ch == '#') {
        cnt++;
      }
      else {
        mx = max(mx, cnt);
        cnt = 0;
      }
    }
    mx = max(mx, cnt);
    if (mx == 0)
      cout << 0 << '\n';
    else
      cout << (mx + 1) / 2 << '\n';
  }
  return 0;
}