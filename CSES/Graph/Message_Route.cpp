#include <bits/stdc++.h>
#define ll long long
using namespace std;
void backtrack(vector<int> &p, int u, int size = 0)
{
  if (p[u] == -1)
  {
    cout << size + 1 << '\n';
    cout << u << ' ';
    return;
  }
  backtrack(p, p[u], size + 1);
  cout << u << ' ';
}

void bfs(int n, int u, vector<int> adj[])
{
  vector<bool> visited(n + 1, false);
  vector<int> p(n + 1, -1);
  queue<int> q;
  q.push(u);
  int curr;
  while (!q.empty())
  {
    curr = q.front();
    if (curr == n)
    {
      backtrack(p, n);
      return;
    }
    q.pop();
    visited[curr] = true;
    for (const int &v : adj[curr])
    {
      if (!visited[v])
      {
        q.push(v);
        p[v] = curr;
        visited[v] = true;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector<int> adj[n + 1];
  while (m--)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(n, 1, adj);
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