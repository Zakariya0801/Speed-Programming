#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

vector<vector<int>> adj;
int maxLen;
bool changed = false;
void bfs(int start, int &n)
{
  vector<int> dist(n + 1, INT_MAX);
  vector<int> p(n + 1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  p[start] = -1;
  int u;
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    for (auto v : adj[u])
    {
      if (dist[v] == INT_MAX)
      {
        q.push(v);
        dist[v] = dist[u] + 1;
        p[v] = u;
      }
      else if (v != p[u])
      {
        maxLen = min(maxLen, dist[v] + dist[u] + 1);
        changed = true;
      }
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  maxLen = n;
  adj.resize(n + 1);
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    bfs(i, n);
  if (!changed)
    cout << "-1\n";
  else
    cout << maxLen << '\n';
}
int main()
{
  fast_io;
  // input_file;
  solve();
}