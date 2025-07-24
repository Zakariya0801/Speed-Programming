#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<int> adj[], int u, vector<int> &visited, bool val)
{
  if (visited[u])
    return;
  visited[u] = val ? 1 : 2;
  for (const auto &v : adj[u])
  {
    if (visited[v] == (val ? 1 : 2))
    {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
    dfs(adj, v, visited, (val ? 0 : 1));
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
  vector<int> visited(n + 1, false);
  bool val = true;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      dfs(adj, i, visited, val);
      // val = val ? 0 : 1;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << visited[i] << ' ';
  }
  cout << '\n';
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