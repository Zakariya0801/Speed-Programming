#include <bits/stdc++.h>
#define ll long long
using namespace std;

void FloydWarshall(vector<vector<ll>> &dist, int N)
{
  for (int i = 1; i <= N; i++)
    dist[i][i] = 0;
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
      {
        if (dist[k][j] != LLONG_MAX && dist[i][k] != LLONG_MAX)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
}

void solve()
{
  int n, m, a, b, q;
  ll weight;
  cin >> n >> m >> q;
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
  while (m--)
  {
    cin >> a >> b >> weight;
    dist[a][b] = min(weight, dist[a][b]);
    dist[b][a] = min(weight, dist[b][a]);
  }
  FloydWarshall(dist, n);
  while (q--)
  {
    cin >> a >> b;
    cout << ((dist[a][b] != LLONG_MAX) ? dist[a][b] : -1) << '\n';
  }
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