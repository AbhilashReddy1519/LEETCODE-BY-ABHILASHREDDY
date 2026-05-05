#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int start, int destiny, vector<vector<int>> &adj, vector<bool>& isVisted, vector<int>& parent) {
  isVisted[start] = true;
  bool found = false;
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    if(node == destiny) {
      found = true;
      break;
    }
    for(int neigh: adj[node]) {
      if(!isVisted[neigh]) {
        isVisted[neigh] = true;
        parent[neigh] = node;
        q.push(neigh);
      }
    }
  }
  vector<int> path;
  if(!found) return path;
  path.push_back(destiny);
  while(parent[destiny] != start) {
    path.push_back(parent[destiny]);
    destiny = parent[destiny];
  }
  path.push_back(start);
  reverse(path.begin(), path.end());
  return path;
}

    int main()
{
  int n, edges;
  cin >> n >> edges;
  vector<vector<int>> adj(n + 1);
  for(int i = 0;i < edges;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> isVisted(n + 1, false);
  vector<int> parent(n + 1);
  for(int i = 0;i < n + 1;i++) parent[i] = i;
  vector<int> ans = solve(1, n, adj, isVisted, parent);
  if(ans.size() == 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << ans.size() << endl;
  for(int i: ans) {
    cout << i << " ";
  }
  return 0;
}