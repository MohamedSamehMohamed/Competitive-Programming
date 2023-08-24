// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
struct Node{
  int x, v;
  long long sumx;
  Node (int _x, int _v, long long _sumx)
  {
    x = _x;
    v = _v;
    sumx = _sumx;
  }
};
const int N = 8e5 + 9;
int n;
vector<pair<int,int>> v;
vector<Node> seg[N];
vector<Node> merge(vector<Node> &l, vector<Node> &r)
{
  vector<Node> ret;
  int i = 0, j = 0;
  int ls = l.size();
  int rs = r.size();
  long long lstSum = 0;
  while(i < ls && j < rs)
  {
    if (l[i].v < r[j].v)
    {
      ret.push_back(l[i++]);
      ret.back().sumx = ret.back().x + lstSum;
      lstSum = ret.back().sumx;
    }else
    {
      ret.push_back(r[j++]);
      ret.back().sumx = ret.back().x + lstSum;
      lstSum = ret.back().sumx;
    }
  }
  while(i < ls)
  {
    ret.push_back(l[i++]);
    ret.back().sumx = ret.back().x + lstSum;
    lstSum = ret.back().sumx;
  }
  while(j < rs)
  {
    ret.push_back(r[j++]);
    ret.back().sumx = ret.back().x + lstSum;
    lstSum = ret.back().sumx;
  }
  return ret;
}
void build(int node = 0, int l = 0, int r = n-1)
{
  if (l == r)
  {
    seg[node] = vector<Node>(1, Node(v[l].first, v[l].second, v[l].first));
    return;
  }
  int m = (l+r)>>1;
  int n1 = node * 2 + 1;
  int n2 = n1 + 1;
  build(n1, l, m);
  build(n2, m+1, r);
  seg[node] = merge(seg[n1], seg[n2]);
}
pair<long long, int> Binary(int idx, int val)
{
  int l = 0, r = seg[idx].size()-1, m, ans = -1;
  while(l <= r)
  {
    m = (l+r)>>1;
    if (seg[idx][m].v <= val)
      ans = m, l = m+1;
    else
      r = m-1;
  }
  if (ans == -1)
    return {0,0};
  return {seg[idx][ans].sumx, ans+1};
}
pair<long long, int> query(int le, int re, int val, int node = 0, int l = 0, int r = n-1)
{
  if (l > re || r < le)
    return {0LL, 0};
  if (l >= le && r <= re)
    return Binary(node, val);
  int m = (l+r)>>1;
  auto L = query(le, re, val, node*2+1, l, m);
  auto R = query(le, re, val, node*2+2, m+1, r);
  return {L.first + R.first, L.second + R.second};
}
int main()
{

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    v.push_back({x, 0});
  }
  for (int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    v[i].second = x;
  }
  sort(v.begin(), v.end());
  build();
  long long ans = 0;
  for (int i = 1; i < n; i++)
  {
    auto cur = query(0, i-1, v[i].second);
    ans += 1LL*cur.second * v[i].first - cur.first;
  }
  printf("%lld\n", ans);
}
