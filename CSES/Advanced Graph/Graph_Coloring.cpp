#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;
int max_clique_size = 0;
vector<int> current_clique;

void dfs(int start, int &n, vector<vector<int>> &adj)
{
  max_clique_size = max(max_clique_size, (int)current_clique.size());
  for (int i = start; i < n; i++)
  {
    bool ok = true;
    for (int u : current_clique)
    {
      if (!binary_search(adj[u].begin(), adj[u].end(), i))
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      current_clique.push_back(i);
      dfs(i + 1, n, adj);
      current_clique.pop_back();
    }
  }
}

bool is_safe(int v, int c, const vector<int> &color, vector<vector<int>> &adj)
{
  for (int u : adj[v])
  {
    if (color[u] == c)
      return false;
  }
  return true;
};

bool color_graph(int pos, int k, vector<int> &color, int &n, vector<int> &order, vector<vector<int>> &adj)
{
  if (pos == n)
    return true;
  int v = order[pos];
  for (int c = 1; c <= k; c++)
  {
    if (is_safe(v, c, color, adj))
    {
      color[v] = c;
      if (color_graph(pos + 1, k, color, n, order, adj))
        return true;
      color[v] = 0;
    }
  }
  return false;
};

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (auto &v : adj)
    sort(v.begin(), v.end());

  dfs(0, n, adj);

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int a, int b)
       { return adj[a].size() > adj[b].size(); });

  int upper = 0;
  {
    vector<int> color(n, 0);
    for (int ii = 0; ii < n; ii++)
    {
      int v = order[ii];
      vector<bool> forbidden(n + 1, false);
      for (int u : adj[v])
      {
        if (color[u])
          forbidden[color[u]] = true;
      }
      int c = 1;
      while (forbidden[c])
        c++;
      color[v] = c;
      upper = max(upper, c);
    }
  }
  for (int k = max_clique_size; k <= upper; k++)
  {
    vector<int> color(n, 0);
    if (color_graph(0, k, color, n, order, adj))
    {
      cout << k << endl;
      for (int i = 0; i < n; i++)
      {
        if (i > 0)
          cout << " ";
        cout << color[i];
      }
      cout << endl;
      break;
    }
  }
}
int main()
{
  fast_io;
  // input_file;
  solve();
  return 0;
}