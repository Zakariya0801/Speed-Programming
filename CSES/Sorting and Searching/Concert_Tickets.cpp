#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  ll x;
  unordered_map<ll, ll> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    arr[x]++;
  }
  vector<pair<ll, ll>> items(arr.begin(), arr.end());
  sort(items.begin(), items.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
       { return a.first < b.first; });
  size_t s = items.size();
  bool done = false;
  ll start, end, mid;
  while (m--)
  {
    done = false;
    cin >> x;
    start = 0;
    end = s - 1;
    if (x == 993334972)
      cout << "checking for " << x << endl;
    while (start < end)
    {
      if (x == 993334972)
        cout << "start = " << start << "  end = " << end << endl;
      mid = start + (end - start) / 2;
      if (end - start == 1) // only applicable with start = 0 and end = 1
      {
        cout << "true for " << items[start].first << " " << items[end].first << endl;
        if (items[end].first <= x && items[end].second != 0)
        {
          cout << items[end].first << '\n';
          items[end].second--;
          done = true;
          break;
        }
        else if (items[start].first <= x && items[start].second != 0)
        {
          cout << items[start].first << '\n';
          items[start].second--;
          done = true;
          break;
        }
        else
        {
          done = true;
          cout << "-1\n";
          break;
        }
      }
      if (items[mid].first == x)
      {
        if (items[mid].second != 0)
        {
          cout << items[mid].first << '\n';
          items[mid].second--;
          done = true;
          break;
        }
        else
        {
          end = mid - 1;
        }
      }
      else if (items[mid].first > x)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    if (done)
      continue;
    if (items[start].first <= x && items[start].second != 0)
    {
      cout << items[start].first << '\n';
      items[start].second--;
    }
    else
      cout << "-1\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("test_input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  solve();
}