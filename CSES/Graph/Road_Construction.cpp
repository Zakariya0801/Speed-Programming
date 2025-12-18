#include <bits/stdc++.h>
#define ll long long
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
  int n, m;
  cin >> n >> m;
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
  int u, v;
  while (m--)
  {
    cin >> u >> v;
    merge(u, v);
    cout << comp << " " << maxComp << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}