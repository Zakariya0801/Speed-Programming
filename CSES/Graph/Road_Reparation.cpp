#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Edge
{
public:
  int v;
  ll weight;
  friend bool operator<(const Edge &e1, const Edge &e2)
  {
    return e1.weight > e2.weight;
  }
};

ll spanningTree(int V, vector<vector<Edge>> &adj)
{
  priority_queue<Edge> pq;

  vector<bool> visited(V, false);
  ll res = 0;

  pq.push({1, 0});

  while (!pq.empty())
  {
    auto p = pq.top();
    pq.pop();

    ll wt = p.weight;
    int u = p.v;

    if (visited[u] == true)
      continue;

    res += wt;
    visited[u] = true;
    for (auto v : adj[u])
    {
      if (visited[v.v] == false)
        pq.push({v.v, v.weight});
    }
  }
  for (int i = 1; i < V; i++)
    if (!visited[i])
      return -1;
  return res;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> adj(n + 1);
  int u, v;
  ll w;
  while (m--)
  {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  // for (int i = 1; i <= n; i++)
  //   adj[0].push_back({i, 0});
  ll val = spanningTree(n + 1, adj);
  if (val == -1)
    cout << "IMPOSSIBLE\n";
  else
    cout << val << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  solve();
}