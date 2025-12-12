#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<tuple<int, bool, int, bool>, ll> dp;

ll validNum(string &num, int i, bool tight, int prev, bool isFirstZero)
{
  if (i >= num.size())
    return 1;

  auto key = make_tuple(i, tight, prev, isFirstZero);
  if (dp.find(key) != dp.end())
    return dp[key];

  int upper = tight ? num[i] - '0' : 9;
  ll sum = 0;

  for (int x = 0; x <= upper; x++)
  {
    if (x == prev && !(isFirstZero && x == 0))
      continue;

    bool newTight = tight && (x == upper);
    bool newIsFirstZero = isFirstZero && (x == 0);

    sum += validNum(num, i + 1, newTight, x, newIsFirstZero);
  }

  return dp[key] = sum;
}

void solve()
{
  string a, b;
  cin >> a >> b;

  dp.clear();
  ll countB = validNum(b, 0, true, -1, true);

  dp.clear();
  ll countA = validNum(a, 0, true, -1, true);

  bool aValid = true;
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] == a[i - 1])
    {
      aValid = false;
      break;
    }
  }
  cout << countB - countA + (aValid ? 1 : 0) << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}