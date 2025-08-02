#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<ll> dp(n + 1);
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = (i <= 6);
    for (int j = 1; j <= min(i, 6); j++)
    {
      dp[i] = (dp[i] + dp[i - j]) % 1000000007;
    }
  }
  cout << dp[n] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}