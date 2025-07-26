#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge
{
  int u;
  int v;
  ll w;
};

vector<int> BellmanFord(vector<ll> &dist, vector<Edge> &edges, int n, int &CycleDetect)
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

void solve()
{
  int n, m, a, b;
  ll weight;
  cin >> n >> m;

  vector<Edge> edges;
  while (m--)
  {
    cin >> a >> b >> weight;
    edges.push_back({a, b, weight});
  }
  for (int i = 1; i <= n; i++)
    edges.push_back({0, i, 0});
  vector<ll> dist(n + 1, LLONG_MAX);
  int CycleDetect;
  vector<int> parent = BellmanFord(dist, edges, n, CycleDetect);
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
  if (cycle.size() == 1)
    cycle.push_back(cycle[0]);
  // cycle.push_back(prev);

  for (const int &v : cycle)
    cout << v << " ";
  cout << '\n';
}

int main()
{
  //   ios::sync_with_stdio(false);
  //   cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  while (t--)
    solve();
}