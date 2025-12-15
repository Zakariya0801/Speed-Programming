#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> depth;
ll findDepth(int v, int p, vector<vector<int>> &adj)
{
  if (depth[v])
    return depth[v];
  ll ans = 0;
  for (const int &u : adj[v])
    if (u != p)
      depth[v] = max(depth[v], 1 + findDepth(u, v, adj));
  return depth[v];
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>>
      adj(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  depth.resize(n + 1, 0);
  findDepth(1, -1, adj);
  vector<ll> ans(n + 1);
  ans[1] = depth[1];
  queue<int> q;
  q.push(1);
  while (!q.empty())
  {
    a = q.front();
    q.pop();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}