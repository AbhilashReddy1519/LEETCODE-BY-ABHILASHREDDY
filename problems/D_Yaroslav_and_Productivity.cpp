#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    vector<int> can(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
      int x;
      cin >> x;
      can[x] = 1;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MIN));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
      for (int nextParity = 0; nextParity < 2; nextParity++)
      {
        if (!can[i])
        {
          int curParity = nextParity;
          dp[i][nextParity] =
              dp[i - 1][curParity] +
              (curParity ? -a[i] : a[i]);
        }
        else
        {
          ll best = LLONG_MIN;
          {
            int curParity = nextParity;
            best = max(best,
                       dp[i - 1][curParity] +
                           (curParity ? -a[i] : a[i]));
          }
          {
            int curParity = nextParity ^ 1;
            best = max(best,
                       dp[i - 1][curParity] +
                           (curParity ? -a[i] : a[i]));
          }
          dp[i][nextParity] = best;
        }
      }
    }

    cout << dp[n][0] << '\n';
  }
}