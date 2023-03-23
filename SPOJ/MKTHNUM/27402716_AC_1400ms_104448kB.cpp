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
struct node;
extern node* empty;
struct node
{
  node *l, *r;
  int frq;
  node()
  {
    frq = 0;
    l = r = this;
  }
  node(int frq, node *l, node *r)
  {
    this->frq = frq;
    this->l = l;
    this->r = r;
  }
};
node *empty = new node;
node *insert(node *root, int val, int nst = -1e9, int nen = 1e9)
{
  if (val < nst || val > nen)return root;
  if (nst == nen)return new node( root->frq + 1, root->l, root->r );
  int m = (nst + nen) >> 1;
  node *nl = insert(root->l, val, nst, m);
  node *nr = insert(root->r, val, m+1, nen);
  return new node(nl->frq + nr->frq, nl, nr);
}
node *roots[N];
int n, m;
int query(node *rst, node *ren, int k, int nst = -1e9, int nen = 1e9)
{
  if (nst == nen)return nst;
  int lsz = ren->l->frq - rst->l->frq;
  int m = (nst + nen)>>1;
  if (lsz >= k)
    return query(rst->l, ren->l, k, nst, m);
  return query(rst->r, ren->r, k-lsz, m+1, nen);
}
int main()
{
  scanf("%d%d", &n, &m);
  roots[0] = empty;
  for(int i = 1; i <= n; i++)
  {
    int x;
    scanf("%d", &x);
    roots[i] = insert(roots[i-1], x);
  }
  while(m--)
  {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", query(roots[l-1], roots[r], k));
  }
}
// poo poo :D:D