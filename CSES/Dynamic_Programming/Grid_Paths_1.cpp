#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid[i];
  if (grid[n - 1][n - 1] == '*')
  {
    cout << "0\n";
    return;
  }
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  dp[n - 1][n - 1] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (i == n - 1 && j == n - 1)
        continue;
      if (grid[i][j] == '*')
        continue;
      if (i + 1 < n)
        dp[i][j] = (dp[i][j] + dp[i + 1][j]) % 1000000007;
      if (j + 1 < n)
        dp[i][j] = (dp[i][j] + dp[i][j + 1]) % 1000000007;
    }
  }
  cout << dp[0][0] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}