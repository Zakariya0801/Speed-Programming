#include <bits/stdc++.h>
using namespace std;

struct Frame
{
  int inL, inR;
  int stage; // 0 = take root, go left; 1 = go right; 2 = output root
  int root;
};

void solve()
{
  int n;
  cin >> n;

  vector<int> preorder(n), inorder(n);
  for (int i = 0; i < n; i++)
    cin >> preorder[i];
  for (int i = 0; i < n; i++)
    cin >> inorder[i];

  vector<int> pos(n + 1);
  for (int i = 0; i < n; i++)
    pos[inorder[i]] = i;

  int preIndex = 0;
  stack<Frame> st;
  st.push({0, n - 1, 0, -1});
  int mid;
  while (!st.empty())
  {
    Frame &f = st.top();

    if (f.inL > f.inR)
    {
      st.pop();
      continue;
    }

    if (f.stage == 0)
    {
      f.root = preorder[preIndex++];
      f.stage = 1;

      mid = pos[f.root];
      st.push({f.inL, mid - 1, 0, -1});
    }
    else if (f.stage == 1)
    {
      f.stage = 2;
      mid = pos[f.root];
      st.push({mid + 1, f.inR, 0, -1});
    }
    else
    {
      cout << f.root << ' ';
      st.pop();
    }
  }
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
