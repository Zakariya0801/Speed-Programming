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