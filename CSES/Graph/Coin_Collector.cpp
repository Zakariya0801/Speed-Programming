#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;
vector<int> coins;
vector<int> comp;
vector<ll> sum;
vector<bool> vis;
stack<int> stk;
void dfs1(int u, vector<vector<int>> &adj)
{
  if (vis[u])
    return;
  vis[u] = true;
  for (auto v : adj[u])
    dfs1(v, adj);
  stk.push(u);
}
ll dfs2(int u, vector<vector<int>> &adj, int k)
{
  if (vis[u])
    return 0;
  vis[u] = true;
  comp[u] = k;
  ll sum = coins[u];
  for (auto v : adj[u])
    sum += dfs2(v, adj, k);
  return sum;
}

vector<int> kahns_Algo(vector<vector<int>> &adj, vector<pair<int, int>> &edges, int n)
{
  queue<int> q;
  vector<int> inDegree(n + 1, 0);
  vector<int> path;
  for (const auto [a, b] : edges)
    inDegree[b]++;
  for (int i = 1; i <= n; i++)
    if (!inDegree[i])
      q.push(i);
  int u;
  while (!q.empty())
  {
    u = q.front();
    path.push_back(u);
    q.pop();
    for (const int &v : adj[u])
    {
      inDegree[v]--;
      if (!inDegree[v])
        q.push(v);
    }
  }
  return path;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  coins.resize(n + 1);
  for (int i = 0; i < n; i++)
    cin >> coins[i + 1];
  int u, v;
  vector<vector<int>> adj(n + 1), adjRev(n + 1);
  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adjRev[v].push_back(u);
  }
  vis.resize(n + 1);
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs1(i, adj);
  vis.assign(n + 1, false);
  comp.resize(n + 1);
  int k = 1;
  sum.push_back(0);
  while (!stk.empty())
  {
    u = stk.top();
    stk.pop();
    if (vis[u])
      continue;
    sum.push_back(dfs2(u, adjRev, k++));
  }
  vector<vector<int>> adjSCC(k + 1);
  vector<pair<int, int>> edges;
  for (int u = 1; u <= n; u++)
    for (auto v : adj[u])
      if (comp[u] != comp[v])
      {
        edges.push_back({comp[u], comp[v]});
        adjSCC[comp[u]].push_back(comp[v]);
      }
  vector<ll> dp(k + 1);
  vector<int> path = kahns_Algo(adjSCC, edges, k);
  for (auto u : path)
  {
    dp[u] += sum[u];
    for (auto v : adjSCC[u])
      dp[v] = max(dp[v], dp[u]);
  }
  cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
}
int main()
{
  fast_io;
  // input_file;
  solve();
}