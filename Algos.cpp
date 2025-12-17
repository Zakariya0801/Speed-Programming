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

// binary lifting for kth ancestor
vector<vector<int>> binaryLifting(int n, vector<int> &p)
{
  int LOG = log2(n) + 1;
  vector<vector<int>> ancestor(n + 1, vector<int>(LOG, -1));
  for (int u = 1; u <= n; u++)
    ancestor[u][0] = p[u];
  for (int i = 1; i < LOG; i++)
    for (int u = 1; u <= n; u++)
      if (ancestor[u][i - 1] != -1)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
  return ancestor;
}

int findKthAncestor(vector<vector<int>> &ancestor, int node, int K, int maxN)
{
  for (int i = maxN - 1; i >= 0; i--)
    if (K & (1 << i))
    {
      if (ancestor[node][i] == -1)
        return -1;
      node = ancestor[node][i];
    }
  return node;
}

// least common ancestor using binary lifting
void dfs(int u, int p, vector<vector<int>> &memo, vector<int> &lev, int log, vector<vector<int>> &g)
{
  memo[u][0] = p;
  for (int i = 1; i <= log; i++)
    memo[u][i] = memo[memo[u][i - 1]][i - 1];
  for (int v : g[u])
  {
    if (v != p)
    {
      lev[v] = lev[u] + 1;
      dfs(v, u, memo, lev, log, g);
    }
  }
}
int LCA(int a, int b, vector<int> &level, vector<vector<int>> &up, int N)
{
  if (level[b] < level[a])
    swap(a, b);
  int d = level[b] - level[a];

  while (d)
  {
    int i = log2(d);
    b = up[b][i];
    d -= (1 << i);
  }

  if (a == b)
    return a;

  for (int i = N - 1; i >= 0; i--)
  {
    if (up[a][i] != -1 && up[a][i] != up[b][i])
    {
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}
void solve()
{
  vector<int> parent = BellmanFordAllSourceCycleDetect(dist, edges, n, CycleDetect);
  if (CycleDetect == -1)
  {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < n - 1; i++)
    if (parent[CycleDetect] != -1 && parent[CycleDetect] != 0)
      CycleDetect = parent[CycleDetect];
  vector<int> cycle;
  int curr = CycleDetect;
  // int prev;

  while (curr != -1 && curr != 0)
  {
    cycle.push_back(curr);
    if (curr == CycleDetect && cycle.size() > 1)
      break;
    // prev = curr;
    curr = parent[curr];
  }

  reverse(cycle.begin(), cycle.end());
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  while (t--)
    solve();
}