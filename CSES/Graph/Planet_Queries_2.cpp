#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> nextV;
vector<bool> visited;
vector<int> len;
vector<vector<int>> ancestor;
int LOG;
void dfs(int v)
{
  if (visited[v])
    return;
  visited[v] = true;
  ancestor[v][0] = nextV[v];
  dfs(nextV[v]);
  len[v] = len[nextV[v]] + 1;
  for (int i = 1; i < LOG; i++)
    if (ancestor[v][i - 1] != -1)
      ancestor[v][i] = ancestor[ancestor[v][i - 1]][i - 1];
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
  int n, q;
  cin >> n >> q;
  LOG = log2(n) + 1;
  nextV.resize(n + 1);
  visited.resize(n + 1, 0);
  len.resize(n + 1, 0);
  ancestor.resize(n + 1, vector<int>(LOG + 1, -1));
  for (int i = 1; i <= n; i++)
    cin >> nextV[i];
  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(i);
  int u, v;
  int cycle;
  while (q--)
  {
    cin >> u >> v;
    cycle = jump(u, len[u]);
    if (jump(u, len[u] - len[v]) == v)
    {
      cout << len[u] - len[v] << '\n';
      continue;
    }
    if (jump(cycle, len[cycle] - len[v]) == v)
    {
      cout << len[u] + len[cycle] - len[v] << '\n';
      continue;
    }
    cout << "-1\n";
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