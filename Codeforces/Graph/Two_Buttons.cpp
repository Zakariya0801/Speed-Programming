// https://codeforces.com/problemset/problem/520/B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dfs(int u, int end, map<int, int> &visited)
{
  stack<int> q;
  q.push(u);
  visited[u] = 0;
  while (!q.empty())
  {
    u = q.top();
    q.pop();
    if (u == end)
      return true;
    if (u < end)
    {
      if (!visited[u * 2])
      {
        q.push(u * 2);
        visited[u * 2] = visited[u] + 1;
        if (u * 2 == end)
          return true;
      }
      if (u > 0)
      {
        q.push(u - 1);
        visited[u - 1] = visited[u] + 1;
        if (u - 1 == end)
          return true;
      }
    }
    else
    {
      if (u > 0)
      {
        q.push(u - 1);
        visited[u - 1] = visited[u] + 1;
        if (u - 1 == end)
          return true;
      }
      if (!visited[u * 2])
      {
        q.push(u * 2);
        visited[u * 2] = visited[u] + 1;
        if (u * 2 == end)
          return true;
      }
    }
  }
  return false;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  map<int, int> visited;
  dfs(n, m, visited);
  cout << visited[m] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}