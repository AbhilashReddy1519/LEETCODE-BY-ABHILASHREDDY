#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> classes(k + 1, 0);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    classes[a]++;
  }
  map<int, int> mp;
  for (int i = 1; i <= k; i++)
  {
    if (classes[i] > 0)
    {
      mp[classes[i]]++;
    }
  }
  int ans = 1;
  for (auto &[freq, count] : mp)
  {
    if (mp.count(freq + 1))
    {
      ans = max(ans, count + mp[freq + 1]);
    }
  }
  cout << ans << '\n';
  return 0;
}