#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> binaryLifting(int n, vector<int> &p)
{
  int LOG = log2(n) + 1;
  vector<vector<int>> ancestor(n + 1, vector<int>(LOG, -1));
  for (int u = 1; u <= n; u++)
    ancestor[u][0] = p[u];
  for (int i = 1; i < LOG; i++)
    for (int u = 1; u <= n; u++)
      if (ancestor[u][i - 1] != -1)
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
  return ancestor;
}

int findKthAncestor(vector<vector<int>> &ancestor, int node, int K, int maxN)
{
  for (int i = maxN - 1; i >= 0; i--)
    if (K & (1 << i))
    {
      if (ancestor[node][i] == -1)
        return -1;
      node = ancestor[node][i];
    }
  return node;
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

  vector<int> parent(n + 1, -1);
  queue<int> Q;
  Q.push(1);
  parent[1] = -1;
  while (!Q.empty())
  {
    a = Q.front();
    Q.pop();
    for (const int &v : adj[a])
    {
      if (v != parent[a])
      {
        parent[v] = a;
        Q.push(v);
      }
    }
  }
  int maxN = log2(n) + 1;

  vector<vector<int>> ancestor = binaryLifting(n, parent);
  int k;
  while (q--)
  {
    cin >> a >> k;
    cout << findKthAncestor(ancestor, a, k, maxN) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("test_input.txt", "r", stdin);
  solve();
}