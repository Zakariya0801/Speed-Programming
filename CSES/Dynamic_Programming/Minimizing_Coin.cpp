#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  ll sum;
  cin >> n >> sum;
  vector<ll> dp(sum + 1, LLONG_MAX);
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  dp[0] = 0;
  for (int s = 1; s <= sum; s++)
  {
    for (int j = 0; j < n; j++)
    {
      if (s >= coins[j] && dp[s - coins[j]] != LLONG_MAX)
        dp[s] = min(dp[s], dp[s - coins[j]] + 1);
    }
  }
  cout << ((dp[sum] == LLONG_MAX) ? -1 : dp[sum]) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}