#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<int> adj[], vector<bool> &visited)
{
  if (visited[v])
    return;
  visited[v] = true;
  for (const auto &neighbor : adj[v])
    dfs(neighbor, adj, visited);
}

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> leads;
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(i, adj, visited);
      leads.push_back(i);
    }
  }
  cout << leads.size() - 1 << '\n';

  for (int j = 0; j < leads.size() - 1; j++)
  {
    cout << leads[j] << ' ' << leads[j + 1] << '\n';
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