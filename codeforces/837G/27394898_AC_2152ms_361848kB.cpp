// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1 << 18, Mx = 2e5;
int n, m;
struct node;
extern node* empty;
struct node
{
  node *l, *r;
  ll Y[2], X[2][2];
  node(int dumy)
  {
    for (int i = 0; i < 2; i++)Y[i] = 0;
    for(int j = 0; j < 2; j++)
      for (int i = 0; i < 2; i++)X[j][i] = 0;
    l = r = this;
  }
  node(node *l = empty, node *r = empty)
  {
    this->l = l;
    this->r = r;
  }
  void cpy (node *p)
  {
    for(int i = 0; i < 2; i++)
      Y[i] = p->Y[i];
    for(int j = 0; j < 2; j++)
    for(int i = 0; i < 2; i++)
      X[j][i] = p->X[j][i];
    l = p->l;
    r = p->r;
  }
};
node *insert(node *root, int idx, int pos, int val, int nst = 0, int nen = Mx)
{
  if (nst > idx || nen < idx)return root;
  if (nen == nst)
  {
    node *nn = new node(0);
    nn->cpy(root);
    nn->Y[pos]+=val;
    return nn;
  }
  int m = (nen+nst)>>1;
  node *nl = insert(root->l, idx, pos, val, nst, m);
  node *nr = insert(root->r, idx, pos, val, m+1, nen);
  node *ret = new node(nl, nr);
  for (int i = 0; i < 2; i++)ret->Y[i] = nl->Y[i] + nr->Y[i];
  for (int j = 0; j < 2; j++)
    for (int i = 0; i < 2; i++)
      ret->X[j][i] = nl->X[j][i] + nr->X[j][i];
  return ret;
}
node *insert1(node *root, int aval, int bval, int idx, int pos, int nst = 0, int nen = Mx)
{
  if (nst > idx || nen < idx)return root;
  if (nen == nst)
  {
    node *nn = new node(0);
    nn->cpy(root);
    nn->X[pos][0]+=aval;
    nn->X[pos][1]+=bval;
    return nn;
  }
  int m = (nen+nst)>>1;
  node *nl = insert1(root->l, aval, bval, idx, pos, nst, m);
  node *nr = insert1(root->r, aval, bval, idx, pos, m+1, nen);
  node *ret = new node(nl, nr);
  for (int i = 0; i < 2; i++)ret->Y[i] = nl->Y[i] + nr->Y[i];
  for (int j = 0; j < 2; j++)
    for (int i = 0; i < 2; i++)
      ret->X[j][i] = nl->X[j][i] + nr->X[j][i];
  return ret;
}
/*
range l:r and variable x
1-how many x1 in range [l:r] that >= x
1-summution of y1 in range [l:r] that x1 >= x
*/
ll query1(node *ns, node *ne, int x, int nst = 0, int nen = Mx)
{
  if (nst >= x)return ne->Y[0] - ns->Y[0];
  if (nen < x)return 0;
  int m = (nen+nst)>>1;
  return query1(ns->l, ne->l, x, nst, m) +
         query1(ns->r, ne->r, x, m+1, nen);
}
ll query2(node *ns, node *ne, int x, int nst = 0, int nen = Mx)
{
  if (nen < x)return ne->Y[1] - ns->Y[1];
  if (nst >= x)return 0;
  int m = (nen+nst)>>1;
  return query2(ns->l, ne->l, x, nst, m) +
         query2(ns->r, ne->r, x, m+1, nen);
}
pair<ll,ll> query3(node *ns, node *ne, int x, int nst = 0, int nen = Mx)
{
  if (nst >= x)return {ne->X[0][0]-ns->X[0][0],ne->X[0][1]-ns->X[0][1]};
  if (nen < x)return {0, 0};
  int m = (nst+nen)>>1;
  auto r1 = query3(ns->l, ne->l, x, nst, m);
  auto r2 = query3(ns->r, ne->r, x, m+1, nen);
  r1.f += r2.f;
  r1.s += r2.s;
  return r1;
}
pair<ll,ll> query4(node *ns, node *ne, int x, int nst = 0, int nen = Mx)
{
  if (nen < x)return {ne->X[1][0]-ns->X[1][0],ne->X[1][1]-ns->X[1][1]};
  if (nst >= x)return {0, 0};
  int m = (nst+nen)>>1;
  auto r1 = query4(ns->l, ne->l, x, nst, m);
  auto r2 = query4(ns->r, ne->r, x, m+1, nen);
  r1.f += r2.f;
  r1.s += r2.s;
  return r1;
}
struct Fun{
  int x1, x2, y1, a, b, y2;
  ll cal(int x)
  {
    if (x <= x1)return y1;
    if (x > x1 && x <= x2)return 1LL*a * x + b;
    return y2;
  }
}a[N];
node *roots[N];
node *empty = new node(0);
ll A[Mx], B[Mx];
int main()
{
  scanf("%d", &n);
  roots[0] = empty;
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d%d%d%d", &a[i].x1, &a[i].x2, &a[i].y1, &a[i].a, &a[i].b, &a[i].y2);
  for (int i = 1; i <= n; i++)
  {
    roots[i] = roots[i-1];
    roots[i] = insert(roots[i], a[i].x1, 0, a[i].y1);
    roots[i] = insert(roots[i], a[i].x2, 1, a[i].y2);
    roots[i] = insert1(roots[i], a[i].a, a[i].b, a[i].x1, 0);
    roots[i] = insert1(roots[i], a[i].a, a[i].b, a[i].x2, 1);
    A[i] += a[i].a;
    B[i] += a[i].b;
  }
  for (int i = 0; i < Mx; i++)A[i]+=A[i-1], B[i]+=B[i-1];
  scanf("%d", &m);
  int l, r, x;
  int Mod = 1e9;
  ll lst = 0;
  while(m--)
  {
    scanf("%d%d%d", &l, &r, &x);
    x = (x + lst)%Mod;
    ll F1 = query1(roots[l-1], roots[r], x);
    ll F2 = query2(roots[l-1], roots[r], x);
    auto F3 = query3(roots[l-1], roots[r], x);
    auto F4 = query4(roots[l-1], roots[r], x);
    ll AA = A[r] - A[l-1];
    ll BB = B[r] - B[l-1];
    ll na = AA - (F3.f + F4.f);
    ll nb = BB - (F3.s + F4.s);
    ll ret = F1 + F2 + na * x + nb;
    printf("%lld\n", ret);
    lst = ret;
  }
}
