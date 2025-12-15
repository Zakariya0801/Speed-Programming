#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  int start = 0, end = n - 1;
  int count = 0;
  while (start <= end)
  {
    if (arr[start] + arr[end] <= x)
    {
      count++;
      start++;
      end--;
    }
    else
    {
      count++;
      end--;
    }
  }
  cout << count << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}