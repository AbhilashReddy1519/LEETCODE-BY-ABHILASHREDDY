#include <bits/stdc++.h>
using namespace std;

void checkRoom(int i, int j, vector<vector<char>>& rooms, int n,int m) {
  rooms[i][j] = '#';
  queue<pair<int,int>> q;
  int directions[4][2]  = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  q.push({i, j});
  while(!q.empty()) {
    auto node = q.front();
    q.pop();
    int x = node.first;
    int y = node.second;
    for(int d = 0;d < 4;d++) {
      int nR = x + directions[d][0];
      int nC = y + directions[d][1];
      if(nR >= 0 && nC >= 0 && nR < n && nC < m && rooms[nR][nC] != '#') {
        rooms[nR][nC] = '#';
        q.push({nR, nC});
      }
    }
  }
}

int solve(vector<vector<char>>& rooms,int n, int m) {
  int count = 0;
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < m;j++) {
      if(rooms[i][j] == '.') {
        checkRoom(i, j, rooms, n, m);
        count++;
      }
    }
  }
  return count;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> rooms(n, vector<char>(m));
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < m;j++) {
      cin >> rooms[i][j];
    }
  }

  cout << solve(rooms, n, m) << endl;
  return 0;
}