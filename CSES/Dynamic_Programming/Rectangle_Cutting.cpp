#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> dp;
int solve(int a, int b)
{
  dp[0][0] = 0;
  for (int i = 1; i <= a; i++)
    dp[i][i] = 0;
  for (int j = 1; j <= b; j++)
    dp[j][j] = 0;

  for (int i = 1; i <= a; i++)
  {
    for (int j = 1; j <= b; j++)
    {
      if (i == j)
        continue;

      int val = INT_MAX;
      for (int k = 1; k < j; k++)
        val = min(val, dp[i][k] + dp[i][j - k] + 1);
      for (int k = 1; k < i; k++)
        val = min(val, dp[k][j] + dp[i - k][j] + 1);

      dp[i][j] = val;
    }
  }
  return dp[a][b];
}

void solve()
{
  int a, b;
  cin >> a >> b;
  int maxi = max(a, b);
  dp.resize(maxi + 1, vector<int>(maxi + 1, INT_MAX));
  cout << solve(a, b) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}