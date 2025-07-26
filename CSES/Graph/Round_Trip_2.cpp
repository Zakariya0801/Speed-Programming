#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool found = false;
int backtrack(vector<int> &visited, int u, int p, int len = 1)
{
  if (visited[u] == p)
  {
    cout << len + 2 << '\n';
    cout << u << " ";
    return u;
  }
  int x = backtrack(visited, visited[u], p, len + 1);
  cout << u << " ";
  return x;
}

bool dfs(int u, vector<int> adj[], vector<int> &visited, int p, vector<bool> &stackVisit)
{
  visited[u] = p;
  stackVisit[u] = true;
  for (auto v : adj[u])
  {
    if (!visited[v])
    {
      visited[v] = u;
      if (dfs(v, adj, visited, u, stackVisit))
        return true;
    }
    else if (stackVisit[v])
    {
      int x = backtrack(visited, u, v);
      cout << v << " " << x << "\n";
      found = true;
      return true;
    }
  }
  stackVisit[u] = false;
  return false;
}

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector<int> adj[n + 1];
  while (m--)
  {
    cin >> a >> b;
    adj[a].push_back(b);
  }
  vector<int> visited(n + 1, 0);
  vector<bool> stackVisit(n + 1, false);
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i] && dfs(i, adj, visited, -1, stackVisit))
      break;
  }
  if (!found)
    cout << "IMPOSSIBLE\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1;
  while (t--)
    solve();
}