#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge
{
  int v;
  ll w;
};

struct Node
{
  int id;
  ll dist;
  bool isDiscounted;
  friend bool operator<(const Node &a, const Node &b)
  {
    return a.dist > b.dist;
  }
};

void dijkstraDiscounted(vector<Edge> adj[], int start, int n, vector<ll> &distDiscount)
{
  priority_queue<Node> q;
  q.push({start, 0, false});
  vector<ll> dist(n + 1, LLONG_MAX);
  while (!q.empty())
  {
    const auto [u, dis, isDiscount] = q.top();
    q.pop();
    if (!isDiscount && dis > dist[u])
      continue;
    if (isDiscount && dis > distDiscount[u])
      continue;
    for (const auto [v, weight] : adj[u])
    {
      if (!isDiscount)
      {
        if (dist[v] > dis + weight)
        {
          dist[v] = dis + weight;
          q.push({v, dis + weight, false});
        }
        if (distDiscount[v] > dis + weight / 2)
        {
          distDiscount[v] = dis + weight / 2;
          q.push({v, dis + weight / 2, true});
        }
      }
      else
      {
        if (distDiscount[v] > dis + weight)
        {
          distDiscount[v] = dis + weight;
          q.push({v, dis + weight, true});
        }
      }
    }
  }
}

void solve()
{
  int n, m, a, b;
  ll w;
  cin >> n >> m;
  vector<Edge> adj[n + 1];
  while (m--)
  {
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
  }
  vector<ll> distDiscount(n + 1, LLONG_MAX);
  dijkstraDiscounted(adj, 1, n, distDiscount);
  cout << distDiscount[n] << '\n';
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