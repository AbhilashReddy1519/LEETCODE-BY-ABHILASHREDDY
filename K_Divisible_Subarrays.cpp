#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  long long K;
  cin >> N >> K;

  unordered_set<long long> seen;
  seen.insert(0);

  long long rem = 0;
  int ans = 0;

  for (int i = 0; i < N; i++)
  {
    long long x;
    cin >> x;

    rem = (rem + x) % K;

    if (seen.count(rem))
    {
      // Found a subarray whose sum is divisible by K.
      ans++;

      // Start a new segment from here.
      seen.clear();
      seen.insert(rem);
    }
    else
    {
      seen.insert(rem);
    }
  }
  cout << ans << '\n';
  return 0;
}