#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(int u, int p, vector<vector<int>> &memo, vector<int> &lev, int log, vector<vector<int>> &g)
{
  memo[u][0] = p;
  for (int i = 1; i <= log; i++)
    if (memo[u][i - 1] != -1)
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

  for (int i = N; i >= 0; i--)
    if (d & (1 << i))
      b = up[b][i];

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
void dfs_prefix_sum(int u, int p, vector<vector<int>> &adj, vector<ll> &counts)
{
  for (int v : adj[u])
  {
    if (v != p)
    {
      dfs_prefix_sum(v, u, adj, counts);
      counts[u] += counts[v];
    }
  }
}
void solve()
{
  int n, q;
  cin >> n >> q;
  vector<vector<int>>
      adj(n + 1);
  vector<ll> counts(n + 1);
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
  dfs(1, 0, memo, lev, log, adj);
  int x;
  while (q--)
  {
    cin >> a >> b;
    counts[a]++;
    counts[b]++;
    x = LCA(a, b, lev, memo, log);
    counts[x]--;
    if (memo[x][0] != -1)
      counts[memo[x][0]]--;
  }
  dfs_prefix_sum(1, 0, adj, counts);
  for (int i = 1; i <= n; i++)
    cout << counts[i] << " ";
  cout << endl;
}

int main()
{
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // freopen("test_input.txt", "r", stdin);
  solve();
  return 0;
}