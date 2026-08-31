#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG = -(1LL << 60);

int main()
{
  int n, k;
  cin >> n >> k;
  ll base = 0;
  vector<ll> d(n + 1);
  for (int i = 1; i <= n; i++)
  {
    ll a, b;
    cin >> a >> b;
    base += a;
    d[i] = b - a;
  }
  vector<vector<ll>> out(k + 1, vector<ll>(2, NEG));
  vector<vector<ll>> in(k + 1, vector<ll>(2, NEG));
  out[0][0] = 0;
  for (int i = 1; i <= n; i++)
  {
    vector<vector<ll>> nout(k + 1, vector<ll>(2, NEG));
    vector<vector<ll>> nin(k + 1, vector<ll>(2, NEG));

    for (int j = 0; j <= k; j++)
    {
      nout[j][0] = max(nout[j][0], out[j][0]);
      nout[j][0] = max(nout[j][0], in[j][1]);
      if (j < k)
        nin[j + 1][1] = max(nin[j + 1][1], out[j][0] + d[i]);
      nin[j][1] = max(nin[j][1], in[j][1] + d[i]);
    }
    out.swap(nout);
    in.swap(nin);
  }
  ll best = 0;
  for (int i = 0; i <= k; i++)
  {
    best = max(best, out[i][0]);
    best = max(best, in[i][1]);
  }
  cout << base + best << '\n';
}