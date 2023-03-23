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
const int N = 1 << 18, Mx = 1e5;
int a[N], n;
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
  node(int sum, node *l = empty, node *r = empty)
  {
    this->sum = sum;
    this->l = l;
    this->r = r;
  }
};
node *insert(node *root, int idx, int val, int nst = 1, int nen = n+1)
{
  if (nst > idx || nen < idx)return root;
  if (nst == nen)return new node(val, root->l, root->r);
  int m = (nst+nen)>>1;
  node *nl = insert(root->l, idx, val, nst, m);
  node *nr = insert(root->r, idx, val, m+1, nen);
  return new node(nl->sum + nr->sum, nl, nr);
}
int query(node *root, int k, int nst = 1, int nen = n+1)
{
  if (nst == nen)return nst;
  int sum = root->l->sum;
  int m = (nen+nst)>>1;
  if (sum <= k)
    return query(root->r, k - sum, m+1, nen);
  return query(root->l, k, nst, m);
}
node *roots[N];
node *empty = new node;
int lst[N];
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", a+i);
    lst[a[i]] = -1;
  }
  roots[n+1] = empty;
  for (int i = n; i > 0; i--)
  {
    roots[i] = roots[i+1];
    if (~lst[a[i]])
      roots[i] = insert(roots[i], lst[a[i]], 0);
    roots[i] = insert(roots[i], i, 1);
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    int L = 1;
    int cnt = 0;
    while(L <= n)
    {
      L = query(roots[L], i);
      cnt++;
    }
    printf("%d ", cnt);
  }

}
