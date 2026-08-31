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
    int n, m;
    cin >> n >> m;
    vector<int> freq(m + 1);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      freq[x]++;
    }
    vector<int> suffix(m + 2, 0);
    for (int x = m; x >= 1; x--)
    {
      suffix[x] = suffix[x + 1] + freq[x];
    }
    int ans = 0;
    for (int x = 1; x <= m; x++)
    {
      int greater = suffix[x + 1];
      int extra = (2 * x <= m ? freq[2 * x] : 0);
      int cur = freq[x] + greater + extra;
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}