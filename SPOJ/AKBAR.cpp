#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

void solve()
{
  int n, r, m;
  cin >> n >> r >> m;
  vector<vector<int>> adj(n + 1);
  int u, v;
  while (r--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<pair<int, int>> q;
  vector<bool> vis(n + 1);
  while (m--)
  {
    cin >> u >> v;
    q.push({u, v});
    vis[u] = true;
  }

  while (!q.empty())
  {
    auto [a, d] = q.front();
    q.pop();
    if (d == 0)
      continue;
    for (auto v : adj[a])
    {
      if (!vis[v])
      {
        vis[v] = true;
        q.push({v, d - 1});
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}
int main()
{
  fast_io;
  // input_file;
  int t;
  cin >> t;
  while (t--)
    solve();
}