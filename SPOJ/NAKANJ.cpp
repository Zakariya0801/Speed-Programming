#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

vector<pair<int, int>> moves = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

struct Param
{
  int x;
  int y;
  int d;
};
bool isValid(int x, int y)
{
  return !(x < 0 || y < 0 || x >= 8 || y >= 8);
}
void solve()
{
  string start, end;
  cin >> start >> end;
  queue<Param> q;
  q.push({start[0] - 'a', start[1] - '1', 0});
  Param p;
  vector<vector<bool>> vis(8, vector<bool>(8));
  while (!q.empty())
  {
    p = q.front();
    if (p.x == end[0] - 'a' && p.y == end[1] - '1')
    {
      cout << p.d << '\n';
      return;
    }
    q.pop();
    for (auto [dx, dy] : moves)
    {
      if (isValid(p.x + dx, p.y + dy) && !vis[p.x + dx][p.y + dy])
      {
        vis[p.x + dx][p.y + dy] = true;
        q.push({p.x + dx, p.y + dy, p.d + 1});
      }
    }
  }
}
int main()
{
  fast_io;
  // input_file;
  int t;
  cin >> t;
  while (t--)
    solve();
}