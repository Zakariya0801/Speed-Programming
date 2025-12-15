#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> depth;
ll findDepth(int v, int p, vector<vector<int>> &adj, vector<ll> &dp)
{
  if (depth[v])
    return depth[v];
  ll ans = 0;
  vector<ll> childDm;
  for (const int &u : adj[v])
  {
    if (u != p)
    {
      depth[v] = max(depth[v], 1 + findDepth(u, v, adj, dp));
      ans = max(ans, dp[u]);
      childDm.push_back(depth[u]);
    }
  }
  sort(childDm.rbegin(), childDm.rend());
  if (childDm.size() == 0)
    dp[v] = 0;
  else if (childDm.size() == 1)
    dp[v] = 1 + childDm[0];
  else
    dp[v] = 2 + childDm[0] + childDm[1];
  dp[v] = max(ans, dp[v]);
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
  vector<ll> dp(n + 1);
  findDepth(1, -1, adj, dp);
  cout << dp[1] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}