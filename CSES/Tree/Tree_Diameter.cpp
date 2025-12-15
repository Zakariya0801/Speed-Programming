#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>>
      adj(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<ll> heights(n + 1);
  vector<ll> parent(n + 1);
  queue<int> q;
  q.push(1);
  ll maxH = 1;
  while (!q.empty())
  {
    a = q.front();
    q.pop();
    for (const int &v : adj[a])
    {
      if (v == parent[a])
        continue;
      heights[v] = max(heights[v], heights[a] + 1);
      parent[v] = a;
      if (heights[maxH] < heights[v])
        maxH = v;
      q.push(v);
    }
  }
  q.push(maxH);
  heights.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  while (!q.empty())
  {
    a = q.front();
    q.pop();
    for (const int &v : adj[a])
    {
      if (v == parent[a])
        continue;
      heights[v] = max(heights[v], heights[a] + 1);
      parent[v] = a;
      if (heights[maxH] < heights[v])
        maxH = v;
      q.push(v);
    }
  }
  cout << heights[maxH] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}