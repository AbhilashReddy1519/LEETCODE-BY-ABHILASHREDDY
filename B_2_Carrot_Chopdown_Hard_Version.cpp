#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1);
    long long total = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      cnt[a]++;
      total += a;
      mx = max(mx, a);
    }
    vector<int> suf(m + 2);
    for (int i = m; i >= 1; i--)
      suf[i] = suf[i + 1] + cnt[i];
    vector<long long> ans(m + 1);
    long long pw = 2;
    for (int k = 1; k <= m; k++)
    {
      if (pw >= mx)
      {
        for (int j = k; j <= m; j++)
          ans[j] = total;
        break;
      }
      int cap = (int)pw - 1;
      long long best = 0;
      for (int x = 1; x <= m; x++)
      {
        int lim = min(cap, m / x);
        long long cur = 0;
        for (int j = 1; j <= lim; j++)
          cur += suf[j * x];
        if (pw * x <= m)
          cur += cnt[pw * x];

        best = max(best, cur);
      }
      ans[k] = best;
      pw *= 2;
      if (pw > m)
        pw = m;
    }
    for (int k = 1; k <= m; k++)
    {
      cout << ans[k] << (k == m ? '\n' : ' ');
    }
  }
  return 0;
}