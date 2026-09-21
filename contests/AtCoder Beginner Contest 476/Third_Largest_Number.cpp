#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(auto &i: nums) cin >> i;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0;i < n;i++) {
    pq.push(nums[i]);
    if(i >= 2) {
      if(pq.size() > 3) pq.pop();
      cout << pq.top() << '\n';
    }
  }
  return 0;
}