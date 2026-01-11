#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define input_file freopen("input.txt", "r", stdin)
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<int> prufer_counts(n + 1, 1);
  vector<int> prufers(n - 2);
  int x;
  for (int i = 0; i < n - 2; i++)
  {
    cin >> x;
    prufer_counts[x]++;
    prufers[i] = x;
  }
  set<int> leaves;
  for (int v = 1; v <= n; v++)
  {
    if (prufer_counts[v] == 1)
      leaves.insert(v);
  }

  int val;
  for (auto v : prufers)
  {
    val = *(leaves.begin());
    leaves.erase(leaves.begin());
    cout << val << " " << v << '\n';
    prufer_counts[v]--;
    if (prufer_counts[v] == 1)
    {
      leaves.insert(v);
    }
  }
  cout << *(leaves.begin()) << " " << n << endl;
}
int main()
{
  fast_io;
  // input_file;
  solve();
}