#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isValid(int i, int j, int n, int m, vector<string> &maze)
{
  if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == '#')
    return false;
  return true;
}

void backtrack(vector<vector<pair<int, char>>> &visited, int i, int j)
{
  if (visited[i][j].first == 0)
    return;
  if (visited[i][j].second == 'L')
    backtrack(visited, i, j + 1);
  else if (visited[i][j].second == 'R')
    backtrack(visited, i, j - 1);
  else if (visited[i][j].second == 'U')
    backtrack(visited, i + 1, j);
  else if (visited[i][j].second == 'D')
    backtrack(visited, i - 1, j);
  cout << visited[i][j].second;
}

vector<vector<pair<int, char>>> bfs(vector<pair<int, int>> starts, vector<string> &maze, int n, int m)
{
  vector<vector<pair<int, char>>> visited(n, vector<pair<int, char>>(m + 1, {-1, '\0'}));
  queue<pair<int, int>> q;
  for (const auto &start : starts)
  {
    visited[start.first][start.second] = {0, '\0'};
    q.push(start);
  }
  pair<int, int> curr;
  vector<pair<int, int>> dir = {{0, 1},
                                {1, 0},
                                {0, -1},
                                {-1, 0}};
  int i, j;
  while (!q.empty())
  {
    curr = q.front();
    q.pop();
    for (auto d : dir)
    {
      i = d.first;
      j = d.second;
      if (isValid(curr.first + i, curr.second + j, n, m, maze) && visited[curr.first + i][curr.second + j].first == -1)
      {
        q.push({curr.first + i, curr.second + j});
        if (i == 0 && j == 1)
          visited[curr.first + i][curr.second + j] = {visited[curr.first][curr.second].first + 1, 'R'};
        else if (i == 0 && j == -1)
          visited[curr.first + i][curr.second + j] = {visited[curr.first][curr.second].first + 1, 'L'};
        else if (i == 1 && j == 0)
          visited[curr.first + i][curr.second + j] = {visited[curr.first][curr.second].first + 1, 'D'};
        else if (i == -1 && j == 0)
          visited[curr.first + i][curr.second + j] = {visited[curr.first][curr.second].first + 1, 'U'};
      }
    }
  }
  return visited;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> maze(n);
  for (int i = 0; i < n; i++)
    cin >> maze[i];
  vector<pair<int, int>> q;
  pair<int, int> start;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (maze[i][j] == 'M')
        q.push_back({i, j});
      else if (maze[i][j] == 'A')
        start = {i, j};
    }
  }
  vector<vector<pair<int, char>>> visitedPlayer = bfs({start}, maze, n, m);
  vector<vector<pair<int, char>>> visitedMonster = bfs(q, maze, n, m);
  for (int i = 0; i < n; i++)
  {
    if (visitedPlayer[i][0].first == 0)
    {
      cout << "YES\n0\n";
      return;
    }
    if (visitedPlayer[i][m - 1].first == 0)
    {
      cout << "YES\n0\n";
      return;
    }
    if (visitedPlayer[i][0].first != -1 && (visitedPlayer[i][0].first < visitedMonster[i][0].first || visitedMonster[i][0].first == -1))
    {
      cout << "YES\n";
      cout << visitedPlayer[i][0].first << '\n';
      backtrack(visitedPlayer, i, 0);
      return;
    }
    if (visitedPlayer[i][m - 1].first != -1 && (visitedPlayer[i][m - 1] < visitedMonster[i][m - 1] || visitedMonster[i][m - 1].first == -1))
    {
      cout << "YES\n";
      cout << visitedPlayer[i][m - 1].first << '\n';
      backtrack(visitedPlayer, i, m - 1);
      return;
    }
  }
  for (int i = 0; i < m; i++)
  {
    if (visitedPlayer[0][i].first == 0)
    {
      cout << "YES\n0\n";
      return;
    }
    if (visitedPlayer[n - 1][i].first == 0)
    {
      cout << "YES\n0\n";
      return;
    }
    if (visitedPlayer[0][i].first != -1 && (visitedPlayer[0][i] < visitedMonster[0][i] || visitedMonster[0][i].first == -1))
    {
      cout << "YES\n";
      cout << visitedPlayer[0][i].first << '\n';
      backtrack(visitedPlayer, 0, i);
      return;
    }
    if (visitedPlayer[n - 1][i].first != -1 && (visitedPlayer[n - 1][i] < visitedMonster[n - 1][i] || visitedMonster[n - 1][i].first == -1))
    {
      cout << "YES\n";
      cout << visitedPlayer[n - 1][i].first << '\n';
      backtrack(visitedPlayer, n - 1, i);
      return;
    }
  }
  cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  while (t--)
    solve();
}