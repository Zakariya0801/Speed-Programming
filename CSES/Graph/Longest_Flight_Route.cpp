#include <bits/stdc++.h>
#define ll long long
using namespace std;

void kahns_Algo(vector<int> adj[], vector<pair<int, int>> &edges, int n, vector<int> &path)
{
  queue<int> q;
  vector<int> inDegree(n + 1, 0);
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
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<pair<int, int>> edges;
  int a, b;
  while (m--)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    edges.push_back({a, b});
  }
  vector<int> path;
  kahns_Algo(adj, edges, n, path);
  vector<ll> dp(n + 1, LLONG_MIN);
  vector<int> p(n + 1, -1);
  dp[1] = 0;
  for (const int &u : path)
  {
    if (dp[u] == LLONG_MIN)
      continue;
    for (const int &v : adj[u])
    {
      if (dp[v] < dp[u] + 1)
      {
        dp[v] = dp[u] + 1;
        p[v] = u;
      }
    }
  }
  if (dp[n] == LLONG_MIN)
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
  int curr = n;
  path.clear();
  while (curr != -1)
  {
    path.push_back(curr);
    curr = p[curr];
  }
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for (const int &x : path)
    cout << x << " ";
  cout << '\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  solve();
}