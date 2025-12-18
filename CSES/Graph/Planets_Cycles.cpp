#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> nextV;
vector<bool> visited;
vector<int> dist;
vector<int> dp;
vector<vector<int>> ancestor;
int LOG;
int cycle_node = -1;
int cycle_len;
void dfs(int v, int di)
{
  if (visited[v])
    return;
  visited[v] = true;
  ancestor[v][0] = nextV[v];
  dist[v] = di;
  if (visited[nextV[v]])
  {
    if (dp[nextV[v]] == 0)
    {
      cycle_len = dist[v] - dist[nextV[v]] + 1;
      cycle_node = nextV[v];
    }
    else
    {
      cycle_len = dp[v];
    }
  }
  else
    dfs(nextV[v], di + 1);
  for (int i = 1; i < LOG; i++)
    if (ancestor[v][i - 1] != -1)
      ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
  if (cycle_node != -1)
  {
    dp[v] = cycle_len;
    if (cycle_node == v)
      cycle_node = -1;
  }
  else
    dp[v] = dp[nextV[v]] + 1;
}
int jump(int v, int k)
{
  if (k < 0)
    return -1;
  for (int i = LOG - 1; i >= 0; i--)
  {
    if (k & (1 << i))
    {
      if (ancestor[v][i] == -1)
        return -1;
      v = ancestor[v][i];
    }
  }
  return v;
}
void solve()
{
  int n;
  cin >> n;
  LOG = log2(n) + 1;
  nextV.resize(n + 1);
  visited.resize(n + 1, 0);
  dist.resize(n + 1, 0);
  dp.resize(n + 1, 0);
  ancestor.resize(n + 1, vector<int>(LOG + 1, -1));
  for (int i = 1; i <= n; i++)
    cin >> nextV[i];
  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(i, 1);
  for (int i = 1; i <= n; i++)
    cout << dp[i] << " ";
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  solve();
}