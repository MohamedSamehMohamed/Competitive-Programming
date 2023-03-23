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
const int N = 1e5+9;
int n, m, a[N];
struct node;
extern node* empty;
struct node
{
  node *l, *r;
  ll sum, lazy;
  node()
  {
    sum = lazy = 0;
    l = r = this;
  }
  node(ll sum, node *l = empty, node *r = empty, ll lazy = 0)
  {
    this->sum = sum;
    this->l = l;
    this->r = r;
    this->lazy = lazy;
  }
};
node *empty = new node;
void push(node *&root, int l, int r)
{
  root->sum += root->lazy * (r - l + 1);
  if (l < r)
  {
    root->l->lazy += root->lazy;
    root->r->lazy += root->lazy;
  }
  root->lazy = 0;
}
node *build(node *root, int nst = 0, int nen = n-1)
{
  if (nst == nen)
  {
    root->sum = a[nst];
    return root;
  }
  int m = (nst+nen)>>1;
  root->l = new node();
  root->r = new node();
  root->l = build(root->l, nst, m);
  root->r = build(root->r, m+1, nen);
  root->sum = root->l->sum + root->r->sum;
  return root;
}
node *insert(node *root, int val, int l, int r, int nst = 0, int nen = n-1)
{
  if (nst > r || nen < l)return root;
  if (nst == nen)return new node(root->sum + val, root->l, root->r, root->lazy);
  if (nst >= l && nen <= r)
  {
    return new node(root->sum, root->l, root->r, root->lazy + val);
  }
  int m = (nst + nen) >> 1;
  node *nl = insert(root->l, val, l, r, nst, m);
  node *nr = insert(root->r, val, l, r, m+1, nen);
  return new node(root->sum+1LL*val*((min(r, nen)-max(l,nst))+1), nl, nr, root->lazy);
}
node *roots[N];
ll query(node *root, int l, int r, int nst = 0, int nen = n-1, ll totlazy = 0)
{
  if (nst > r || nen < l)return 0;
  totlazy += root->lazy;
  if (nst >= l && nen <= r)return root->sum + 1LL*totlazy * (nen-nst+1);
  int m = (nst + nen)>>1;
  return query(root->l, l, r, nst, m, totlazy) + query(root->r, l, r, m+1, nen, totlazy);
}
void print(node *root, int l = 0 ,int r = n-1)
{
  printf("%d %d %lld %lld\n", l, r, root->sum, root->lazy);
  if (l == r)return;
  int m = (l+r)>>1;
  print(root->l, l, m);
  print(root->r, m+1, r);
}
int main()
{
  scanf("%d%d", &n, &m);
  roots[0] = empty;
  for (int i = 0; i < n; i++)scanf("%d", a+i);
  roots[0] = build(roots[0]);
  int cur = 0;
  while(m--)
  {
    char type;
    int l, r, d;
    scanf(" %c", &type);
    switch (type){
      case 'C':
      scanf("%d%d%d", &l, &r, &d);
      l--;r--;
      cur++;
      roots[cur] = insert(roots[cur-1], d, l, r);
      break;
      case 'Q':
      scanf("%d%d", &l, &r);
      l--;r--;
      printf("%lld\n", query(roots[cur], l, r));
      break;
      case 'H':
      scanf("%d%d%d", &l, &r, &d);
      l--;r--;
      printf("%lld\n", query(roots[d], l, r));
      break;
      case 'B':
      scanf("%d", &d);
      cur = d;
      break;
    }
    // int pr;scanf("%d", &pr);if (pr) print(roots[cur], 0, n-1);
  }
}
