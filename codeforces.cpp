#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp(1000000001, -1);
ll pizza(int n, vector<ll>& dp)
{
  if(n <=2) return 0;
  if(dp[n] != -1) return dp[n];
  int m3 = 0;
  ll maxVal = 0;
  for(int m1=1 ; m1<n ; m1++)
  {
    maxVal = max(maxVal, ll(m1));
    for(int m2=m1 ; m2<n ; m2++)
    {
      m3 = n-m1-m2;
      if(m3 < m2) continue;
      cout << "checking for valid " << m1 << " " << m2 << " " << m3 << '\n';
      maxVal = max(maxVal, pizza(m3, dp));
    }
  } 
  return dp[n] = maxVal;
  
}

void solve()
{
  int n;
  cin >> n;
  cout << pizza(n,dp) << '\n';
  
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t ;
  cin >> t;
  while (t--)
    solve();
}