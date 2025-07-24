#include <bits/stdc++.h>
#define ll long long
using namespace std;
int backtrack(vector<int> &visited, int u, int p, int len = 1)
{
  if (visited[u] == p)
  {
    cout << len + 2 << '\n';
    cout << u << " ";
    return u;
  }
  int x = backtrack(visited, visited[u], p, len + 1);
  cout << u << " ";
  return x;
}

void dfs(int u, vector<int> adj[], vector<int> &visited, int p)
{
  visited[u] = p;
  for (auto v : adj[u])
  {
    if (!visited[v])
      dfs(v, adj, visited, u);
    else if (v != p)
    {
      int x = backtrack(visited, u, v);
      cout << v << " " << x << "\n";
      exit(0);
    }
  }
}

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector<int> adj[n + 1];
  while (m--)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> visited(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
      dfs(i, adj, visited, -1);
  }
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