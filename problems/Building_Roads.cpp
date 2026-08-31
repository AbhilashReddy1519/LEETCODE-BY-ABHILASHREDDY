#include <bits/stdc++.h>
using namespace std;

class DSU {
  public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
      for(int i = 0;i < n + 1;i++) {
        parent.push_back(i);
        rank.push_back(1);
      }
    }

    int getParent(int u) {
      if(parent[u] == u) return u;
      return parent[u] = getParent(parent[u]);
    }

    void unionPair(int u, int v) {
      int parentU = getParent(u);
      int parentV = getParent(v);
      if(rank[parentV] > rank[parentU]) {
        parent[parentU] = parentV;
        rank[parentV]++;
      } else {
        parent[parentV] = parentU;
        rank[parentU]++;
      }
    }
};

int main() {
  int n, edges;
  cin >> n >> edges;
  DSU* sol = new DSU(n);
  for(int i = 0;i < edges;i++) {
    int u, v;
    cin >> u >> v;
    sol->unionPair(u, v);
  }
  vector<int> nodes;
  for(int i = 1;i < n + 1;i++) {
    if(sol->getParent(i) == i) nodes.push_back(i);
  }
  cout << nodes.size() - 1 << '\n';
  for(int i = 0;i < nodes.size() - 1;i++) {
    cout << nodes[i] << " " << nodes[i + 1] << '\n';
  }
  return 0;
}