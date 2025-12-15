#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int u, int p, vector<vector<int>> &memo, vector<int> &lev, int log, vector<vector<int>> &g)
{
  memo[u][0] = p;
  for (int i = 1; i <= log; i++)
    memo[u][i] = memo[memo[u][i - 1]][i - 1];
  for (int v : g[u])
  {
    if (v != p)
    {
      lev[v] = lev[u] + 1;
      dfs(v, u, memo, lev, log, g);
    }
  }
}
int lca(int u, int v, int log, vector<int> &lev, vector<vector<int>> &memo)
{
  if (lev[u] < lev[v])
    swap(u, v);

  for (int i = log; i >= 0; i--)
    if ((lev[u] - pow(2, i)) >= lev[v])
      u = memo[u][i];
  if (u == v)
    return u;
  for (int i = log; i >= 0; i--)
  {
    if (memo[u][i] != memo[v][i])
    {
      u = memo[u][i];
      v = memo[v][i];
    }
  }

  return memo[u][0];
}
void solve()
{
  int n, q;
  cin >> n >> q;
  vector<vector<int>>
      adj(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a;
    adj[a].push_back(i + 2);
    adj[i + 2].push_back(a);
  }
  int log = (int)ceil(log2(n));
  vector<int> lev(n + 1);
  vector<vector<int>> memo(n + 1, vector<int>(log + 1, -1));
  dfs(1, 1, memo, lev, log, adj);
  while (q--)
  {
    cin >> a >> b;
    cout << lca(a, b, log, lev, memo) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("test_input.txt", "r", stdin);
  solve();
}