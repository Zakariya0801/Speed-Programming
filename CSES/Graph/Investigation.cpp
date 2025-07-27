#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge
{
  int v;
  ll w;
};
class Node
{
public:
  int v;
  ll dist;
  friend bool operator<(const Node &a, const Node &b)
  {
    return a.dist > b.dist;
  }
};

class Answer
{
public:
  ll minCost;
  ll numberOfCost;
  ll minFlights;
  ll maxFlights;
};

void dijkstra(vector<Edge> adj[], int start, vector<Answer> &dist)
{
  priority_queue<Node> q;
  q.push({start, 0});
  dist[start] = {0, 1, 0, 0};
  int u;
  ll d;
  while (!q.empty())
  {
    u = q.top().v;
    d = q.top().dist;
    q.pop();
    if (d > dist[u].minCost)
      continue;
    for (Edge e : adj[u])
    {
      if (dist[e.v].minCost > dist[u].minCost + e.w)
      {
        dist[e.v] = {dist[u].minCost + e.w,
                     dist[u].numberOfCost,
                     dist[u].minFlights + 1,
                     dist[u].maxFlights + 1};
        q.push({e.v, dist[e.v].minCost});
      }
      else if (dist[e.v].minCost == dist[u].minCost + e.w)
      {
        dist[e.v] = {dist[e.v].minCost,
                     (dist[e.v].numberOfCost + dist[u].numberOfCost) % 1000000007,
                     min(dist[e.v].minFlights, dist[u].minFlights + 1),
                     max(dist[e.v].maxFlights, dist[u].maxFlights + 1)};
      }
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<Edge> adj[n + 1];
  int u, v;
  ll w;
  while (m--)
  {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  vector<Answer> dist(n + 1, {LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX});
  dijkstra(adj, 1, dist);
  cout << dist[n].minCost << " " << dist[n].numberOfCost << " " << dist[n].minFlights << " " << dist[n].maxFlights << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin.tie(0);
  solve();
}