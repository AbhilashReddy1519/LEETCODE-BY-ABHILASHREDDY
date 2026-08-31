#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, sz;

  DSU(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);

    for (int i = 1; i <= n; i++)
      parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
      return;

    if (sz[a] < sz[b])
      swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> p[i];
    DSU dsu(n);

    for (int i = 1; i <= n; i++) {
      if (i + x <= n)
        dsu.unite(i, i + x);

      if (i + y <= n)
        dsu.unite(i, i + y);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (dsu.find(i) != dsu.find(p[i])) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}