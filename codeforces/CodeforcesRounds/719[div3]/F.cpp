#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N];
int n, t, k;
int seen[N], bit[N];
int sum(int r)
{
  int ret = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1)
    ret += bit[r];
  return ret;
}

void add(int idx, int delta)
{
  for (; idx < n; idx = idx | (idx + 1))
    bit[idx] += delta;
}
void byHand(int cur)
{
  while(cur + 1 < N && a[cur + 1] != -1)
  {
    a[cur] = a[cur+1];
    cur++;
  }
}
int main()
{
  cin >> n >> t;
  cin >> k;
  memset(seen, -1, sizeof seen);
  for (int i = 1; i <= n; i++)
  {
    cout << "? " << 1 << " " << i << endl;
    int answer;
    cin >> answer;
    seen[i] = answer;
  }
  for (int kth = 1; kth <= n; kth++)
  {
    int l = 1, r = n, m, ans = -1;
    while(l <= r)
    {
      m = (l+r) >> 1;
      int answer = seen[m];
      if (m-answer >= kth)
        ans = m, r = m-1;
      else
        l = m + 1;
    }
    if (ans == -1)break;
    a[kth] = ans;
  }
  t--;
  cout << "! " << a[k] << endl;
  byHand(k);
  while(t--)
  {
    cin >> k;
    cout << "! " << a[k] << endl;
    byHand(k);
  }
}
