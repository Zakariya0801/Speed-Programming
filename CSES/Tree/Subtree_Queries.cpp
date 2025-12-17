#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sums;
vector<int> parent;
ll dfs(int u, int p, vector<vector<int>> &adj, vector<int> &val)
{
  if (sums[u])
    return sums[u];
  sums[u] = val[u];
  for (auto v : adj[u])
    if (v != p)
    {
      sums[u] += dfs(v, u, adj, val);
      parent[v] = u;
    }
  return sums[u];
}
void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> val(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> val[i];
  int a, b;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  sums.resize(n + 1);
  parent.resize(n + 1, -1);
  dfs(1, -1, adj, val);
  int type, s, x;
  ll diff;
  while (q--)
  {
    cin >> type;
    if (type == 2)
    {
      cin >> s;
      cout << sums[s] << '\n';
      continue;
    }
    cin >> s >> x;
    diff = x - val[s];
    val[s] = x;
    if (diff == 0)
      continue;
    while (s != -1)
    {
      sums[s] += diff;
      s = parent[s];
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}