#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// const int maxN = 1e5;

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

void FloydWarshall(vector<vector<ll>> &dist, int N)
{
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
      {
        if (dist[k][j] != LLONG_MAX && dist[i][k] != LLONG_MAX)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}
struct EdgeBellman
{
  int u;
  int v;
  ll w;
};
set<int> BellmanFordOpposite(vector<ll> &dist, vector<EdgeBellman> &edges, int n)
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
vector<int> BellmanFordAllSourceCycleDetect(vector<ll> &dist, vector<EdgeBellman> &edges, int n, int &CycleDetect)
{
  dist[0] = 0;
  vector<int> parent(n + 1, -1);
  // int CycleDetect = -1;
  while (n--)
  {
    CycleDetect = -1;
    for (const auto [u, v, w] : edges)
    {
      if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
      {
        CycleDetect = v;
        dist[v] = dist[u] + w;
        parent[v] = u;
      }
    }
  }
  return parent;
}

vector<ll> dijkstra(int N, vector<Edge> G[], int start)
{
  vector<ll> dist(N + 1, LLONG_MAX);
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
  return dist;
}

void backtrack(vector<int> &visited, int u, int len = 0)
{
  if (u == 1)
  {
    cout << len + 1 << '\n';
    cout << u << " ";
    return;
  }
  backtrack(visited, visited[u], len + 1);
  cout << u << ' ';
}

void bfs(vector<int> adj[], int u, int end, int n)
{
  vector<int> visited(n + 1, 0);
  queue<int> q;
  q.push(u);
  visited[u] = -1;
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for (int v : adj[u])
    {
      if (v == end)
      {
        visited[v] = u;
        backtrack(visited, end);
        cout << '\n';
        return;
      }
      if (!visited[v])
      {
        q.push(v);
        visited[v] = u;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

void dfs(int v, vector<int> adj[], vector<bool> &visited)
{
  if (visited[v])
    return;
  visited[v] = true;
  for (const auto &neighbor : adj[v])
    dfs(neighbor, adj, visited);
}

void solve()
{
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