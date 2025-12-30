#include <bits/stdc++.h>
#define ll long long
#define input_file freopen("input.txt", "r", stdin)
#define f0n(n) for (int i = 0; i < n; i++)
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
  }
  ll FULL = (1 << n) - 1;
  vector<vector<ll>> dp(FULL + 1, vector<ll>(n));
  ll mask, newMask;
  ll ways;
  ll MOD = 1000000007;
  dp[1][0] = 1;
  for (int mask = 1; mask <= FULL; mask += 2)
  {
    f0n(n)
    {
      if (!(mask & (1 << i)))
        continue;
      ways = dp[mask][i];
      if (!ways)
        continue;
      for (auto v : adj[i])
      {
        if (mask & (1 << v))
          continue;
        newMask = mask | 1 << v;
        dp[newMask][v] = (dp[newMask][v] + ways) % MOD;
      }
    }
  }
  cout << dp[FULL][n - 1] << '\n';
}
int main()
{
  // input_file;
  solve();
}