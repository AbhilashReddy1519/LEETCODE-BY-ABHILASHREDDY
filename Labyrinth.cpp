#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, string path, string &ans, vector<vector<char>> &labyrinth, map<char, vector<int>>& mpDir, int& n, int& m) {
  if(labyrinth[i][j] == 'B') {
    if(path.length() < ans.length() || ans.empty()) {
      ans = path;
    }
    return;
  }
  char temp = labyrinth[i][j];
  labyrinth[i][j] = '#';
  for(auto it: mpDir) {
    int nR = i + it.second[0];
    int nC = j + it.second[1];
    if(nR >= 0 && nC >= 0 && nR < n && nC < m && labyrinth[nR][nC] != '#') {
      // path.append(to_string(it.first)); // or 
      path.push_back(it.first);
      solve(nR, nC, path, ans, labyrinth, mpDir, n, m);
      path.pop_back();
    }
  }
  labyrinth[i][j] = temp;
}

int main() {
  int n, m;
  cin >> n >> m;
  int x = -1, y = -1;
  vector<vector<char>> labyrinth(n, vector<char>(m));
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < m;j++) {
      cin >> labyrinth  [i][j];
      if(labyrinth[i][j] == 'A') {
        x = i;
        y = j;
      }
    }
  }
  if(x == -1 || y == -1) {
    cout << "NO" << endl;
    return 0;
  }
  map<char, vector<int>> mpDir = {
    {'D', {1, 0}},
    {'U', {-1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
  };

  string ans = "";
  solve(x, y, "", ans, labyrinth, mpDir, n, m);
  if(ans.empty()) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << '\n';
    cout << ans.length() << '\n';
    cout << ans << endl;
  }
  return 0;
}