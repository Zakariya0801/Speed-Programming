#include <bits/stdc++.h>
using namespace std;

vector<long> dp;
long getWays(int n, vector<long> c)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return 0;
  long v = 0;
  for (const long &val : c)
    v += getWays(n - val, c);
  return dp[n] = v;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<long> c(m);
  long v;
  dp.resize(n + 1, 0);
  for (int i = 0; i < m; i++)
    cin >> c[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (const long &val : c)
    {
      if (val <= i)
        dp[i] += dp[i - val];
    }
  }
  cout << getWays(n, c) << '\n';
}
