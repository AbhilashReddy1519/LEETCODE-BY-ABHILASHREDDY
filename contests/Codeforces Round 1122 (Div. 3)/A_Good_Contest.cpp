#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int num;
    cin >> num;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    int mini = min({p1, p2, p3});
    int maxi = max({p1, p2, p3});

    cout << (abs(num - maxi)) + (maxi - mini) << "\n";
  }
}