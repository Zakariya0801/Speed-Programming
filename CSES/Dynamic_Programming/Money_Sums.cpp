#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
  dp[0][0] = true;
  // for (int i = 0; i < n; i++)
  //   dp[1][arr[i]] = true;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      if (dp[i - 1][j])
        dp[i][j] = true;
      else if (j >= arr[i - 1] && dp[i - 1][j - arr[i - 1]])
        dp[i][j] = true;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= sum; i++)
    if (dp[n][i])
      ans.push_back(i);
  cout << ans.size() << '\n';
  for (const int &a : ans)
    cout << a << " ";
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}