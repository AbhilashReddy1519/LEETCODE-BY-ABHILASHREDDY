#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int half = n / 2;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (i >= half)
      sum += a;
  }
  cout << sum;
  return 0;
}