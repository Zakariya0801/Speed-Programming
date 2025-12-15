#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<ll> &subord)
{
  for (auto child : adj[node])
  {
    dfs(child, adj, subord);
    subord[node] += subord[child] + 1;
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  int x;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> x;
    adj[x].push_back(i + 2);
  }
  vector<ll> subord(n + 1);
  dfs(1, adj, subord);
  for (int i = 1; i <= n; i++)
    cout << subord[i] << " ";
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}