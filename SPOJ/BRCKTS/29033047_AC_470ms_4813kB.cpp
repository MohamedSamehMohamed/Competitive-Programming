// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std ;
const int N = 1 << 18;
struct node{
  int open, closed, correct;
  void empty()
  {
    open = closed = correct = 0;
  }
  void merge(node l, node r)
  {
    empty();
    correct = min(l.open, r.closed);
    l.open -= correct;
    r.closed -= correct;
    correct += l.correct + r.correct;
    open = l.open + r.open;
    closed = l.closed + r.closed;
  }
}seg[N];
int n, q;
string x;
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node].empty();
    if (x[l] == '(')
      seg[node].open++;
    else
      seg[node].closed++;
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  build(n1, l, m);
  build(n1+1, m+1, r);
  seg[node].merge(seg[n1], seg[n1+1]);
}
void update(int idx, int node = 0, int l = 0, int r = n-1)
{
  if (l > idx || r < idx)return;
  if (l == r)
  {
    seg[node].empty();
    if (x[l] == '(')
      seg[node].open++;
    else
      seg[node].closed++;
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  update(idx, n1, l, m);
  update(idx, n1+1, m+1, r);
  seg[node].merge(seg[n1], seg[n1+1]);
}
void query()
{
  if (n&1)
  {
    cout <<"NO\n";
    return;
  }
  if (seg[0].correct == n/2)
    cout <<"YES\n";
  else
    cout <<"NO\n";
}
void solve()
{
  cin >> x >> q;
  build();
  while(q--)
  {
    int k;
    cin >> k;
    if (k == 0)
    {
      query();
    }else
    {
      x[k-1] = (x[k-1] == '('? ')': '(');
      update(k-1);
    }
  }
}
int main()
{
  FAST
  int t = 1;
  while (cin >> n)
  {
    cout <<"Test " << t++ <<":\n";
    solve();
  }
}
