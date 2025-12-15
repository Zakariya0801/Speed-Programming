#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  set<int> values;
  int x;
  while (n--)
  {
    cin >> x;
    values.insert(x);
  }
  cout << values.size() << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}