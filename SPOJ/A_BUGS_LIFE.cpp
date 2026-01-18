#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

bool dfs(int u, vector<vector<int>> &adj, vector<int> &vis, int val = 1)
{
  vis[u] = val;
  for (auto v : adj[u])
  {
    if (vis[v] && vis[v] == vis[u])
      return true;
    else if (!vis[v])
      if (dfs(v, adj, vis, (val == 1) ? 2 : 1))
        return true;
  }
  return false;
}

void solve(int i)
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n + 1, 0);
  cout << "Scenario #" << i;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      if (dfs(i, adj, vis))
      {
        cout << ":\nSuspicious bugs found!\n";
        return;
      }
    }
  }
  cout << ":\nNo suspicious bugs found!\n";
}
int main()
{
  fast_io;
  // input_file;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    solve(i);
}