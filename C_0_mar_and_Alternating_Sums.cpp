#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& nums) {
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i < n;i++) {
      cin >> arr[i];
    }

    cout << solve(n, arr) << "\n"; 
  }

  return 0;
}