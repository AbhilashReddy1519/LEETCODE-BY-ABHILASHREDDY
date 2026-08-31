#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int sum, int n, int k, vector<int> &cur)
{
  if (i == n)
  {
    int rem = k - sum;
    if (rem % n == 0)
    {
      cur.push_back(rem / n);
      for (int x : cur)
        cout << x << ' ';
      cout << '\n';
      cur.pop_back();
    }
    return;
  }

  for (int x = 0; sum + i * x <= k; ++x)
  {
    cur.push_back(x);
    dfs(i + 1, sum + i * x, n, k, cur);
    cur.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> cur;
  dfs(1, 0, n, k, cur);

  return 0;
}