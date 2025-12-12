#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<int> &arr, int start, int end)
{
  if (start == end)
    return arr[end];
  if (start >= end)
    return 0;
  if (arr[start] > arr[end])
    start++;
  ll val = 0;
  val = max(val, arr[start] + solve(arr, start + 1, end));
  val = max(val, arr[end] + solve(arr, start, end - 1));
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}