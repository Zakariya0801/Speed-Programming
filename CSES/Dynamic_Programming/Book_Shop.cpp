#include <bits/stdc++.h>
#define ll long long
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
  vector<ll> dp(W + 1, 0);
  for (int i = 1; i <= wt.size(); i++)
    for (int j = W; j >= wt[i - 1]; j--)
      dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
  return dp[W];
}

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
    cin >> prices[i];
  vector<int> pages(n);
  for (int i = 0; i < n; i++)
    cin >> pages[i];
  cout << knapsack(x, pages, prices) << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}