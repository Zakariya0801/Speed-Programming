#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> isShop(n + 1);
  int u, v;
  while (k--)
  {
    cin >> u;
    isShop[u] = true;
  }
  vector<vector<int>> adj(n + 1);
  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vector<ll>> dist(n + 1, vector<ll>(2, LLONG_MAX));
  vector<vector<int>> closest(n + 1, vector<int>(2));
  queue<int> q;
  for (int i = 1; i <= n; i++)
  {
    if (isShop[i])
    {
      dist[i][0] = 0;
      closest[i][0] = i;
      q.push(i);
    }
  }
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for (auto v : adj[u])
    {
      if (dist[v][0] > dist[u][0] + 1)
      {
        dist[v][1] = dist[v][0];
        closest[v][1] = closest[v][0];
        dist[v][0] = dist[u][0] + 1;
        closest[v][0] = closest[u][0];
        q.push(v);
      }
      else if (dist[v][1] > dist[u][0] + 1 && closest[v][0] != closest[u][0])
      {
        dist[v][1] = dist[u][0] + 1;
        closest[v][1] = closest[u][0];
      }
    }
  }
  vector<ll> ans(n + 1);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = LLONG_MAX;
    if (dist[i][0] != 0)
      ans[i] = dist[i][0];
  }
  for (int i = 1; i <= n; i++)
  {
    if (dist[i][0] == LLONG_MAX || dist[i][1] == LLONG_MAX)
      continue;
    int u = closest[i][0];
    int v = closest[i][1];
    ans[u] = min(ans[u], dist[i][1] + dist[i][0]);
    ans[v] = min(ans[v], dist[i][1] + dist[i][0]);
  }
  for (int i = 1; i <= n; i++)
  {
    if (ans[i] == LLONG_MAX)
      cout << "-1 ";
    else
      cout << ans[i] << ' ';
  }
  cout << '\n';
}
int main()
{
  fast_io;
  // input_file;
  solve();
}