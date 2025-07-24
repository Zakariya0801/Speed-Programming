#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge
{
  int u;
  int v;
  ll w;
};

set<int> BellmanFord(vector<ll> &dist, vector<Edge> &edges, int n)
{
  dist[1] = 0;
  while (--n)
  {
    for (const auto [u, v, w] : edges)
    {
      if (dist[u] != LLONG_MIN && dist[u] + w > dist[v])
        dist[v] = dist[u] + w;
    }
  }
  set<int> cycle_nodes;
  for (const auto [u, v, w] : edges)
  {
    if (dist[u] != LLONG_MIN && dist[u] + w > dist[v])
      cycle_nodes.insert(v);
  }
  return cycle_nodes;
}

void solve()
{
  int n, m, a, b;
  ll weight;
  cin >> n >> m;

  vector<Edge> edges;
  vector<int> adj[n + 1];
  while (m--)
  {
    cin >> a >> b >> weight;
    adj[a].push_back(b);
    edges.push_back({a, b, weight});
  }
  vector<ll> dist(n + 1, LLONG_MIN);
  set<int> cycle_nodes = BellmanFord(dist, edges, n);
  vector<bool> visited(n + 1, false);
  queue<int> q, cycle_q;
  q.push(1);
  while (!q.empty())
  {
    a = q.front();
    q.pop();
    if (visited[a])
      continue;
    visited[a] = true;

    if (cycle_nodes.count(a))
      cycle_q.push(a);

    for (const int v : adj[a])
      if (!visited[v])
        q.push(v);
  }

  visited.assign(n + 1, false);
  bool cycle_reach = false;
  while (!cycle_q.empty())
  {
    a = cycle_q.front();
    cycle_q.pop();
    if (visited[a])
      continue;
    visited[a] = true;
    if (a == n)
    {
      cycle_reach = true;
      break;
    }
    for (const int v : adj[a])
      if (!visited[v])
        cycle_q.push(v);
  }
  if (cycle_reach)
    cout << "-1\n";
  else
    cout << dist[n] << '\n';
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