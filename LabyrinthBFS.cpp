#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, int& ex, int& ey, vector<vector<char>> &labyrinth, vector<vector<bool>> &visited, vector<vector<char>> &parent, vector<pair<char, pair<int, int>>> &dir, int n, int m)
{
  visited[i][j] = true;
  queue<pair<int,int>> q;
  q.push({i, j});
  while(!q.empty()) {
    auto node = q.front();
    int x = node.first;
    int y = node.second;
    q.pop();
    if(labyrinth[x][y] == 'B') {
      ex = x;
      ey = y;
      return;
    }
    for(auto d: dir) {
      int rx = x + d.second.first;
      int cy = y + d.second.second;
      if(rx >= 0 && cy >= 0 && rx < n && cy < m && !visited[rx][cy] && labyrinth[rx][cy] != '#') {
        parent[rx][cy] = d.first;
        visited[rx][cy] = true;
        q.push({rx, cy});
      }
    }

  }
  return;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int x = -1, y = -1;
  vector<vector<char>> labyrinth(n, vector<char>(m));
  vector<vector<char>> parent(n, vector<char>(m));
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> labyrinth[i][j];
      if (labyrinth[i][j] == 'A')
      {
        x = i;
        y = j;
      }
    }
  }
  if (x == -1 || y == -1)
  {
    cout << "NO" << endl;
    return 0;
  }
  vector<pair<char, pair<int, int>>> dir = {
      {'D', {1, 0}},
      {'U', {-1, 0}},
      {'L', {0, -1}},
      {'R', {0, 1}}};

  int ex = -1, ey = -1;
  solve(x, y, ex, ey, labyrinth, visited, parent, dir, n, m);
  if(ex == -1 || ey == -1) {
    cout << "NO" << endl;
    return 0;
  }
  string path = "";

  while (labyrinth[ex][ey] != 'A') {
    char c = parent[ex][ey];
    path.push_back(c);
    if (c == 'U')
      ex++;
    else if (c == 'D')
      ex--;
    else if (c == 'L')
      ey++;
    else
      ey--;
  }

  reverse(path.begin(), path.end());

  cout << "YES\n";
  cout << path.size() << "\n";
  cout << path << "\n";
  return 0;
}