#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      long long need = i + 1;
      if (arr[i] < need) {
        ok = false;
        break;
      }
      long long extra = arr[i] - need;
      arr[i + 1] += extra;
    }
    if (ok && arr[n - 1] < n)
      ok = false;

    cout << (ok ? "YES" : "NO") << '\n';
  }
}