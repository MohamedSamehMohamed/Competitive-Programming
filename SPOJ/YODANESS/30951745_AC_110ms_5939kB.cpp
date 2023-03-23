#include<bits/stdc++.h>
using namespace std;
const int N = 30009;
int a[N], n;
struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
}bit;
int main()
{
  int t;cin >> t;
  while(t--)
  {
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
      string x;cin >> x;
      mp[x] = i;
    }
    for (int i = 0; i < n; i++)
    {
      string x;cin >> x;
      a[i] = mp[x];
    }
    bit.init();
    long long answer = 0;
    for (int i = n-1; ~i; i--)
    {
      answer += bit.get(a[i]-1);
      bit.add(a[i], 1);
    }
    cout << answer << "\n";
  }
}
