#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("test_input.txt", "r", stdin)
using namespace std;
void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<set<ll>> adj(n + 1);
  for (ll i = 0; i < m; i++)
  {
    ll x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  stack<ll> st;
  for (ll i = 1; i <= n; i++)
    if (adj[i].size() % 2)
    {
      cout << "IMPOSSIBLE\n";
      return;
    }
  vector<ll> path;
  st.push(1);
  while (st.size() > 0)
  {
    ll x = st.top();
    if (adj[x].size() == 0)
    {
      st.pop();
      path.push_back(x);
    }
    else
    {

      ll z = *(adj[x].begin());
      adj[x].erase(z);
      adj[z].erase(x);
      st.push(z);
    }
  }
  if (path.size() != (m + 1))
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (auto &i : path)
    cout << i << " ";
}

int main()
{
  fast_io;
  // input_file;
  solve();
}