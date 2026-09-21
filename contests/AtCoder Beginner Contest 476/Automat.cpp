#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;

  ll oneDollers, kDollers;
  cin >> oneDollers >> kDollers;

  vector<ll> desserts(n), drinks(m);

  for(auto &i: desserts) cin >> i;
  for(auto &i: drinks) cin >> i;

  sort(desserts.begin(), desserts.end());
  sort(drinks.begin(), drinks.end());

  vector<ll> dessertPrefix(n + 1, 0);
  vector<ll> drinkPrefix(m + 1, 0);
  vector<ll> kBillPrefix(m + 1, 0);

  for(int i = 0; i < n; i++) {
    dessertPrefix[i + 1] = dessertPrefix[i] + desserts[i];
  }

  for(int i = 0; i < m; i++) {
    drinkPrefix[i + 1] = drinkPrefix[i] + drinks[i];

    ll kBills = (drinks[i] + k - 1) / k;
    kBillPrefix[i + 1] = kBillPrefix[i] + kBills;
  }

  ll answer = 0;

  for(int i = 0; i <= m; i++) {
    if(kBillPrefix[i] > kDollers) break;

    ll money = oneDollers + kDollers * k - drinkPrefix[i];

    int lo = 0, hi = n;

    while(lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;

      if(dessertPrefix[mid] <= money)
        lo = mid;
      else
        hi = mid - 1;
    }

    answer = max(answer, (ll)i + lo);
  }

  cout << answer;

  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   int n, m, k;
//   cin >> n >> m >> k;
//   int oneDollers, kDollers;
//   cin >> oneDollers >> kDollers;
//   vector<int> desserts(n), drinks(m);
//   for(auto &i: desserts) cin >> i;
//   for(auto &i: drinks) cin >> i;

//   sort(drinks.begin(), drinks.end());
//   int noOfDrinks = 0;
//   for(int i = 0;i < m;i++) {
//     int kBills = (drinks[i] + k - 1)/k; // upperbound;
//     int change = kBills * k - drinks[i];
//     if(kDollers >= kBills) {
//       kDollers -= kBills;
//       oneDollers +=  change;
//       noOfDrinks++;
//     } else break;
//   }

//   sort(desserts.begin(), desserts.end());
//   if(k > 0) oneDollers += k * kDollers;
//   for(int i = 0;i < n;i++) {
//     if(desserts[i] >= oneDollers) {
//       noOfDrinks++;
//       oneDollers -= desserts[i];
//     } else break;
//   }

//   cout << noOfDrinks;
//   return 0;
// }


// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
//   int n, m, k;
//   cin >> n >> m >> k;
//   int oneDollers, kDollers;
//   cin >> oneDollers >> kDollers;
//   vector<int> desserts(n), drinks(m);
//   for(auto &i: desserts) cin >> i;
//   for(auto &i: drinks) cin >> i;

//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

//   for(int i = 0;i < m;i++) {
//     int diff = drinks[i] % k;
//     pq.push({diff, drinks[i]});
//   }

//   int noOfDrinks = 0;
//   while(!pq.empty()) {
//     int kBills = (pq.top().second + k - 1)/k; // upperbound;
//     int change = kBills * k - pq.top().second;
//     if(kDollers >= kBills) {
//       kDollers -= kBills;
//       oneDollers +=  change;
//       noOfDrinks++;
//     } else break;
//     pq.pop();
//   }

//   sort(desserts.begin(), desserts.end());
//   if(kDollers > 0) oneDollers += k * kDollers;
//   for(int i = 0;i < n;i++) {
//     if(desserts[i] >= oneDollers) {
//       noOfDrinks++;
//       oneDollers -= desserts[i];
//     } else break;
//   }

//   cout << noOfDrinks;
//   return 0;
// }