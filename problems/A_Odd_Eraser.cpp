#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    int first, last;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      if (i == 0)
        first = a;
      if (i == n - 1)
        last = a;
    }

    cout << gcd(first, last) << "\n";
  }
  return 0;
}