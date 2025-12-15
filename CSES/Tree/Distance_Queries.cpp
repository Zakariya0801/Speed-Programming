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
int LCA(int a, int b, vector<int> &level, vector<vector<int>> &up, int N)
{
  if (level[b] < level[a])
    swap(a, b);
  int d = level[b] - level[a];

  while (d)
  {
    int i = log2(d);
    b = up[b][i];
    d -= (1 << i);
  }

  if (a == b)
    return a;

  for (int i = N - 1; i >= 0; i--)
  {
    if (up[a][i] != -1 && up[a][i] != up[b][i])
    {
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
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
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int log = (int)ceil(log2(n));
  vector<int> lev(n + 1);
  vector<vector<int>> memo(n + 1, vector<int>(log + 1, -1));
  dfs(1, 1, memo, lev, log, adj);
  int x;
  while (q--)
  {
    cin >> a >> b;
    x = LCA(a, b, lev, memo, log);
    cout << lev[a] + lev[b] - 2 * lev[x] << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("test_input.txt", "r", stdin);
  solve();
}