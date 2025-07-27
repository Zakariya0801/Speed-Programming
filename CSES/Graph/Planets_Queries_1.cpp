#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n, q;
  cin >> n >> q;
  int v;
  const int LOG = 30;
  vector<vector<int>> ancestor(n + 1, vector<int>(LOG, 0));
  for (int u = 1; u <= n; u++)
  {
    cin >> v;
    ancestor[u][0] = v;
  }
  for (int i = 1; i < LOG; i++)
  {
    for (int u = 1; u <= n; u++)
    {
      ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
  }
  int k;
  while (q--)
  {
    cin >> v >> k;
    for (int i = 0; i < LOG; i++)
    {
      if (k & (1 << i))
      {
        v = ancestor[v][i];
      }
    }
    cout << v << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin.tie(0);
  solve();
}