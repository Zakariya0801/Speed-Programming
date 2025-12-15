#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int v, int parent, vector<vector<int>> &dp, vector<vector<int>> &adj)
{
  for (const int &u : adj[v])
  {
    if (u != parent)
    {
      dfs(u, v, dp, adj);
      dp[v][0] += max(dp[u][0], dp[u][1]);
    }
  }
  for (const int &u : adj[v])
    if (u != parent)
      dp[v][1] = max(dp[v][1], dp[u][0] + 1 + dp[v][0] - max(dp[u][0], dp[u][1]));
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<vector<int>> dp(n + 1, vector<int>(2));
  dfs(1, -1, dp, adj);
  cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}