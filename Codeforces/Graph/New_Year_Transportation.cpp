// https://codeforces.com/problemset/problem/500/A
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dfs(vector<int> adj[], int u, int end, vector<bool> &visited)
{
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty())
  {
    u = q.front();
    q.pop();
    visited[u] = true;
    for (const int &v : adj[u])
    {
      if (v == end)
        return true;
      if (!visited[v])
      {
        q.push(v);
      }
    }
  }
  return false;
}

void solve()
{
  int n, t;
  cin >> n >> t;
  vector<int> adj[n + 2];
  int x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    adj[i + 1].push_back(i + 1 + x);
  }
  vector<bool> visited(n + 1, false);
  if (dfs(adj, 1, t, visited))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}