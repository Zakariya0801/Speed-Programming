#include <bits/stdc++.h>
#define fast_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define ll
#define inputFile freopen("input.txt", "r", stdin);

using namespace std;

vector<bool> bfs(int v, int n, vector<vector<int>> &adj)
{
  vector<bool> visited(n + 1);
  queue<int> q;
  q.push(v);
  visited[v] = true;
  while (!q.empty())
  {
    v = q.front();
    q.pop();
    for (auto u : adj[v])
    {
      if (!visited[u])
      {
        visited[u] = true;
        q.push(u);
      }
    }
  }
  return visited;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<vector<int>> adjRev(n + 1);
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adjRev[v].push_back(u);
  }
  vector<bool> visited = bfs(1, n, adj);
  vector<bool> visitedRev = bfs(1, n, adjRev);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      cout << "NO\n";
      cout << 1 << " " << i << '\n';
      return;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (!visitedRev[i])
    {
      cout << "NO\n";
      cout << i << " " << 1 << '\n';
      return;
    }
  }
  cout << "YES\n";
}
int main()
{
  fast_IO;
  // inputFile;
  solve();
}