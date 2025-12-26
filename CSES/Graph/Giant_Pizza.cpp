#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

vector<bool> visited;
stack<int> stk;
vector<int> comp;
void dfs1(int s, vector<vector<int>> &adj)
{
  if (visited[s])
    return;
  visited[s] = true;
  for (const int &v : adj[s])
    dfs1(v, adj);
  stk.push(s);
}
void dfs2(int s, vector<vector<int>> &adj, int k)
{
  if (comp[s] != -1)
    return;
  comp[s] = k;
  for (const int &v : adj[s])
    if (comp[v] == -1)
      dfs2(v, adj, k);
}
int negateVal(int v, int &n)
{
  if (v < n)
    return v + n;
  return v - n;
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(m + m + 1), adjRev(m + m + 1);
  visited.resize(m + m + 1, false);
  char u_ch, v_ch;
  int u_val, v_val;
  while (n--)
  {
    cin >> u_ch >> u_val >> v_ch >> v_val;
    if (u_ch == '-')
      u_val = negateVal(u_val, m);
    if (v_ch == '-')
      v_val = negateVal(v_val, m);
    adj[negateVal(u_val, m)].push_back(v_val);
    adj[negateVal(v_val, m)].push_back(u_val);
    adjRev[u_val].push_back(negateVal(v_val, m));
    adjRev[v_val].push_back(negateVal(u_val, m));
  }
  for (int i = 1; i <= 2 * m; i++)
    if (!visited[i])
      dfs1(i, adj);
  int c = 0;
  comp.resize(m + m + 1, -1);
  while (!stk.empty())
  {
    u_val = stk.top();
    stk.pop();
    if (comp[u_val] != -1)
      continue;
    dfs2(u_val, adjRev, c);
    c++;
  }
  vector<char> assignments(m + 1);
  for (int i = 1; i <= m; i++)
  {
    if (comp[i] > comp[negateVal(i, m)])
      assignments[i] = '+';
    else if (comp[i] < comp[negateVal(i, m)])
      assignments[i] = '-';
    else
    {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  for (int i = 1; i <= m; i++)
    cout << assignments[i] << ' ';
  cout << '\n';
}
int main()
{
  fast_io;
  // input_file;
  solve();
}