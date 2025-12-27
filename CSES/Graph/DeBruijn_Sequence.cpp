#include <bits/stdc++.h>
#define ll long long
#define fast_io                \
  ios::sync_with_stdio(false); \
  cin.tie(0)

using namespace std;

string debrujin(int n, string digits)
{
  int k = digits.size();
  ll kn = 1;
  for (int i = 0; i < n - 1; i++)
    kn *= k;
  // next vertex = (u*k + d) % k^n
  vector<int> nextVCount(kn, 0);
  stack<pair<int, int>> stk;
  stk.push({0, -1});
  vector<int> circuit;
  pair<int, int> p;
  int v, u;
  while (!stk.empty())
  {
    p = stk.top();
    u = p.first;
    if (nextVCount[u] < k)
    {
      v = ((ll)u * k + nextVCount[u]) % kn;
      stk.push({v, nextVCount[u]});
      nextVCount[u]++;
    }
    else
    {
      if (p.second != -1)
        circuit.push_back(p.second);
      stk.pop();
    }
  }
  reverse(circuit.begin(), circuit.end());
  string ans;
  for (int i = 0; i < n - 1; i++)
    ans += digits[0];
  for (auto i : circuit)
    ans += digits[i];
  return ans;
}

void solve()
{
  int n;
  cin >> n;
  string digits = "01";
  cout << debrujin(n, digits) << '\n';
}
int main()
{
  fast_io;
  solve();
}