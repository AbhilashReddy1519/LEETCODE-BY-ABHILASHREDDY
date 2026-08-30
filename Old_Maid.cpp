#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum = 0;
  unordered_map<int, int> mp;
  for(int i = 0;i < n;i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

  for(auto it: mp) {
    if(it.second % 2 == 1) sum += it.first;
  }

  cout << sum << endl;
  return 0;
}