#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;
vector<int> parent;
vector<int> len;
vector<int> depth;
int comp;
int maxComp = 0;
int find(int x)
{
  if (parent[x] != x)
    parent[x] = find(parent[x]);
  return parent[x];
}

void merge(int x, int y)
{
  int lx = find(x);
  int ly = find(y);
  if (lx == ly)
    return;
  if (depth[lx] > depth[ly])
  {
    parent[ly] = lx;
    len[lx] += len[ly];
  }
  else if (depth[lx] < depth[ly])
  {
    parent[lx] = ly;
    len[ly] += len[lx];
  }
  else
  {
    parent[lx] = ly;
    depth[ly]++;
    len[ly] += len[lx];
  }
  maxComp = max(maxComp, max(len[lx], len[ly]));
  comp--;
}
void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  set<pair<int, int>> edges;
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    if (u > v)
      swap(u, v);
    edges.insert({u, v});
  }
  set<pair<int, int>> toRemove;
  vector<pair<int, int>> toRemoveEdges;
  for (int i = 0; i < k; i++)
  {
    cin >> u >> v;
    if (u > v)
      swap(u, v);
    toRemove.insert({u, v});
    toRemoveEdges.push_back({u, v});
  }

  comp = n;
  parent.resize(n + 1);
  len.resize(n + 1);
  depth.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    len[i] = 1;
    depth[i] = 1;
  }
  for (auto e : edges)
  {
    if (toRemove.find(e) == toRemove.end())
      merge(e.first, e.second);
  }
  stack<int> comps;
  comps.push(comp);
  for (int i = k - 1; i > 0; i--)
  {
    merge(toRemoveEdges[i].first, toRemoveEdges[i].second);
    comps.push(comp);
  }
  while (!comps.empty())
  {
    cout << comps.top() << ' ';
    comps.pop();
  }
}
int main()
{
  fast_io;
  // input_file;
  solve();
}