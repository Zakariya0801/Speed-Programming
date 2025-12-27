#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;
void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<set<ll>> adj(n + 1);
  vector<int> inDegree(n + 1);
  vector<int> outDegree(n + 1);
  for (ll i = 0; i < m; i++)
  {
    ll x, y;
    cin >> x >> y;
    adj[x].insert(y);
    // adj[y].insert(x);
    inDegree[y]++;
    outDegree[x]++;
  }
  stack<ll> st;
  if (outDegree[1] - inDegree[1] != 1 || inDegree[n] - outDegree[n] != 1)
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (ll i = 2; i < n; i++)
    if (inDegree[i] != outDegree[i])
    {
      cout << "IMPOSSIBLE\n";
      return;
    }
  vector<ll> path;
  st.push(1);
  vector<bool> vis(n + 1);
  while (st.size() > 0)
  {
    ll x = st.top();
    if (adj[x].size() == 0)
    {
      st.pop();
      path.push_back(x);
      vis[x] = true;
    }
    else
    {

      ll z = *(adj[x].begin());
      adj[x].erase(z);
      st.push(z);
    }
  }
  for (int i = 1; i <= n; i++)
    if (adj[i].size())
    {
      cout << "IMPOSSIBLE\n";
      return;
    }
  reverse(path.begin(), path.end());
  for (auto &i : path)
    cout << i << " ";
}

int main()
{
  fast_io;
  // input_file;
  solve();
}