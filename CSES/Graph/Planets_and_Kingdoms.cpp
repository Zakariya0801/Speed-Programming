#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

vector<bool> visited;
stack<int> stk;
vector<int> king;
void dfs(int s, vector<vector<int>> &adj)
{
  if (visited[s])
    return;
  visited[s] = true;
  for (const int &v : adj[s])
    dfs(v, adj);
  stk.push(s);
}
void dfs(int s, vector<vector<int>> &adj, int val)
{
  if (visited[s])
    return;
  visited[s] = true;
  king[s] = val;
  for (const int &v : adj[s])
    dfs(v, adj, val);
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1), adjRev(n + 1);
  visited.resize(n + 1);
  int u, v;

  while (m--)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adjRev[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!visited[i])
      dfs(i, adj);
  int k = 1;
  king.resize(n + 1);
  visited.assign(n + 1, false);
  while (!stk.empty())
  {
    u = stk.top();
    stk.pop();
    if (visited[u])
      continue;
    dfs(u, adjRev, k);
    k++;
  }
  cout << k - 1 << '\n';
  for (int i = 1; i <= n; i++)
    cout << king[i] << " ";
  cout << '\n';
}
int main()
{
  fast_io;
  // input_file;
  solve();
}