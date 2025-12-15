#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  vector<int> sizes(m);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int j = 0; j < m; j++)
    cin >> sizes[j];
  sort(arr.begin(), arr.end());
  sort(sizes.begin(), sizes.end());
  int i = 0;
  int j = 0;
  int count = 0;
  while (i < n)
  {
    while (arr[i] > sizes[j] && j < m && !((arr[i] - k) <= sizes[j] && sizes[j] <= (arr[i] + k)))
      j++;
    if (j < m && (arr[i] - k) <= sizes[j] && sizes[j] <= (arr[i] + k))
    {
      count++;
      j++;
    }
    i++;
  }
  cout << count << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}