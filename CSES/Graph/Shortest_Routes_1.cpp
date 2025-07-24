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

void dijkstra(vector<Edge> G[], int start, int N, vector<ll> &dist, vector<int> &p)
{
  priority_queue<Node> Q;
  Q.push({start, 0});
  dist[start] = 0;
  while (!Q.empty())
  {
    ll d = Q.top().dist;
    int u = Q.top().id;
    Q.pop();
    if (d > dist[u])
      continue;
    for (Edge e : G[u])
    {
      if (dist[e.v] > d + e.w)
      {
        dist[e.v] = d + e.w;
        Q.push({e.v, d + e.w});
      }
    }
  }
}

void solve()
{
  int n, m, a, b;
  ll weight;
  cin >> n >> m;
  vector<Edge> G[n + 1];
  while (m--)
  {
    cin >> a >> b >> weight;
    G[a].push_back({b, weight});
    // G[b].push_back({a, weight});
  }
  vector<ll> dist(n + 1, LLONG_MAX);
  vector<int> p(n + 1, -1);
  dijkstra(G, 1, n, dist, p);
  for (int i = 1; i <= n; i++)
    cout << dist[i] << " ";
  cout << endl;
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