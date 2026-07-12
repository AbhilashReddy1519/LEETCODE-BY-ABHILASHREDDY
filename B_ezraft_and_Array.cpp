#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n == 2)
    {
      cout << -1 << '\n';
      continue;
    }
    if (n == 1)
    {
      cout << 1 << '\n';
      continue;
    }
    cout << 1 << " " << 2 << " ";
    int64 cur = 3;
    for (int i = 3; i <= n; i++)
    {
      cout << cur << " ";
      cur *= 2;
    }
    cout << '\n';
  }
}