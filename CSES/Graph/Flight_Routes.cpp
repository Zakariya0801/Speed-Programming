#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge
{
  int v;
  ll w;
};
struct Node
{
  int id;
  ll dist;
  friend bool operator<(const Node &a, const Node &b)
  {
    return a.dist > b.dist;
  }
};

void dijkstra(vector<Edge> G[], int start, int N, vector<vector<ll>> &dist, int k)
{
  priority_queue<Node> Q;
  Q.push({start, 0});
  dist[start][0] = 0;
  while (!Q.empty())
  {
    ll d = Q.top().dist;
    int u = Q.top().id;
    Q.pop();
    if (d > dist[u][k - 1])
      continue;
    for (Edge e : G[u])
    {
      if (dist[e.v][k - 1] > d + e.w)
      {
        dist[e.v][k - 1] = d + e.w;
        sort(dist[e.v].begin(), dist[e.v].end());
        Q.push({e.v, d + e.w});
      }
    }
  }
}

void solve()
{
  int n, m, a, b, k;
  ll weight;
  cin >> n >> m >> k;
  vector<Edge> G[n + 1];
  while (m--)
  {
    cin >> a >> b >> weight;
    G[a].push_back({b, weight});
    // G[b].push_back({a, weight});
  }
  vector<vector<ll>> dist(n + 1, vector<ll>(k, LLONG_MAX));
  dijkstra(G, 1, n, dist, k);
  for (int i = 0; i < k; i++)
    cout << dist[n][i] << " ";
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