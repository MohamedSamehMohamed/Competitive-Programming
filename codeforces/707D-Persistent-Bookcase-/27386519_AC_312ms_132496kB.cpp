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
int n, m, q;
struct node;
extern node* empty;
struct node
{
  node *l, *r;
  int sum, lazy;
  node()
  {
    sum = lazy = 0;
    l = r = this;
  }
  node(int sum, int lazy, node *l = empty, node *r = empty)
  {
    this->lazy = lazy;
    this->sum = sum;
    this->l = l;
    this->r = r;
  }
  node (node *p)
  {
    sum = p->sum;
    lazy = p->lazy;
    l = p->l;
    r = p->r;
  }
};
void push(node *&root, int l, int r)
{
  if (root->lazy&1)
  {
    root->sum = (r-l+1) - root->sum;
    root->l = new node(root->l);
    root->r = new node(root->r);
    root->l->lazy++;
    root->r->lazy++;
    root->lazy = 0;
  }
}
node *insert(node *root, int idx, int l = 0, int r = n * m - 1)
{
  push(root, l, r);
  if (idx < l || idx > r)return root;
  if (l == r)
    return new node(1, 0, root->l, root->r);
  int m = (l+r)>>1;
  node *nl = insert(root->l, idx, l, m);
  node *nr = insert(root->r, idx, m+1, r);
  push(nl, l, m);
  push(nr, m+1, r);
  return new node(nl->sum + nr->sum,0, nl, nr);
}
node *remove(node *root, int idx, int l = 0, int r = n * m - 1)
{
  push(root, l, r);
  if (idx < l || idx > r)return root;
  if (l == r)
    return new node(0, 0, root->l, root->r);
  int m = (l+r)>>1;
  node *nl = remove(root->l, idx, l, m);
  node *nr = remove(root->r, idx, m+1, r);
  push(nl, l, m);
  push(nr, m+1, r);
  return new node(nl->sum+nr->sum,0, nl, nr);
}
int get(int val, int lazy)
{
  if (lazy&1)val^=1;
  return val^1;
}
node *add(node *root, int l, int r, int nst = 0, int nen = n * m -1)
{
  push(root, nst, nen);
  if (nst > r || nen < l)return root;
  if (nst == nen)
    return new node(get(root->sum, root->lazy), 0, root->l, root->r);
  if (nst >= l && nen <= r){
    node *nn = new node();
    nn->sum = root->sum;
    nn->lazy = root->lazy+1;
    nn->l = root->l;
    nn->r = root->r;
    push(nn, nst, nen);
    return nn;
  }
  int m = (nst+nen)>>1;
  node *nl = add(root->l, l, r, nst, m);
  node *nr = add(root->r, l, r, m+1, nen);
  return new node(nl->sum + nr->sum, 0, nl, nr);
}
int query(node *root){push(root, 0, n * m-1);return root->sum;}
node *empty = new node;
node *roots[N];
int main()
{
  roots[0] = empty;
  scanf("%d%d%d", &n, &m, &q);
  int cur = 0;
  while(q--)
  {
    int type, i, j;
    scanf("%d%d", &type, &i);
    if (type == 4)
    {
      roots[cur+1] = roots[i];
      cur++;
    }
    else if (type == 1)
    {
      // insert
      scanf("%d", &j);
      i--;j--;
      int idx = i * m + j;
      roots[cur+1] = insert(roots[cur], idx);
      cur++;
    }else if (type == 2)
    {
      // remove
      scanf("%d", &j);
      i--;j--;
      int idx = i * m + j;
      roots[cur+1] = remove(roots[cur], idx);
      cur++;
    }else
    {
      // invert
      i--;
      int l = i * m;
      int r = l + m-1;
      roots[cur+1] = add(roots[cur], l, r);
      cur++;
    }
    printf("%d\n", query(roots[cur]));
  }
}
