#include <bits/stdc++.h>
#define ll long long
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

vector<vector<int>> board(8, vector<int>(8, 0));
int dx[] = {2, 1, -1, 2, -2, 1, -1, -2};
int dy[] = {1, 2, 2, -1, 1, -2, -2, -1};

class Node
{
public:
  int count;
  int x;
  int y;
  friend bool operator<(const Node &n1, const Node &n2)
  {
    return n1.count > n2.count;
  }
};

bool isValid(int x, int y)
{
  return 0 <= x && x < 8 && 0 <= y && y < 8;
}

int counter(int x, int y)
{
  int cnt = 0;
  int Xn, Yn;

  for (int i = 0; i < 8; i++)
  {
    Xn = x + dx[i];
    Yn = y + dy[i];
    if (isValid(Xn, Yn) && !board[Xn][Yn])
      cnt++;
  }
  return cnt;
}

bool dfs(int x, int y, int step)
{
  board[x][y] = step;
  if (step == 64)
    return true;
  priority_queue<Node> q;
  int Xn, Yn;
  for (int i = 0; i < 8; i++)
  {
    Xn = x + dx[i];
    Yn = y + dy[i];
    if (!isValid(Xn, Yn) || board[Xn][Yn])
      continue;
    q.push({counter(Xn, Yn), Xn, Yn});
  }
  Node n;
  while (!q.empty())
  {
    n = q.top();
    q.pop();
    if (dfs(n.x, n.y, step + 1))
      return true;
  }
  board[x][y] = 0;
  return false;
}

void solve()
{
  int x, y;
  cin >> x >> y;
  x--;
  y--;
  dfs(y, x, 1);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
      cout << board[i][j] << " ";
    cout << '\n';
  }
}
int main()
{
  // input_file;
  solve();
}