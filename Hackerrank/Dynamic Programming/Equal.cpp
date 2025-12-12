#include <bits/stdc++.h>
using namespace std;

struct VectorHash
{
  size_t operator()(const vector<int> &v) const
  {
    size_t seed = v.size();
    for (auto &i : v)
    {
      seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

unordered_map<vector<int>, int, VectorHash> dp;

vector<int> addExcept(vector<int> arr, int skip, int v)
{
  for (int i = 0; i < arr.size(); i++)
    if (i != skip)
      arr[i] += v;
  return arr;
}

int maxIndex(vector<int> &arr)
{
  int maxi = INT_MIN;
  for (int i = 0; i < arr.size(); i++)
    if (arr[maxi] < arr[i])
      maxi = i;
  return maxi;
}
bool found = false;
int equal(vector<int> arr)
{
  bool isEqual = true;
  for (int i = 1; i < arr.size(); i++)
    if (arr[i] != arr[i - 1])
    {
      isEqual = false;
      break;
    }
  if (isEqual)
  {
    found = true;
    return 0;
  }
  if (dp[arr])
    return dp[arr];
  if (found)
    return 0;
  int val = INT_MAX;
  int maxi = maxIndex(arr);
  val = min(val, 1 + equal(addExcept(arr, maxi, 1)));
  val = min(val, 1 + equal(addExcept(arr, maxi, 2)));
  val = min(val, 1 + equal(addExcept(arr, maxi, 5)));
  dp[arr] = val;
  return val;
}
void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << equal(arr) << endl;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--)
    solve();
}
