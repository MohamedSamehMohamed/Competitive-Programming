// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 20;
int seg[N<<1], ans[N], n, q;
void upd(int pos, int val, int node = 0, int l = 0, int r = N-1)
{
 if (l > pos || r < pos)return; 
 if (l == r)
 {
  ans[pos] += val; 
  seg[node] += val; 
  return; 
 }
 int m = (l+r)>>1;
 int n1 = node * 2 + 1;
 int n2 = n1 + 1;
 upd(pos, val, n1, l, m);
 upd(pos, val, n2, m+1, r); 
 seg[node] = seg[n1] + seg[n2]; 
}
void del_kth(int kth, int node = 0, int l = 0, int r = N-1)
{
 if (l == r)
 {
  ans[l]--; 
  seg[node]--; 
  return; 
 }
 int m = (l+r)>>1; 
 int n1 = node * 2 + 1;
 int n2 = n1 + 1; 
 if (seg[n1] >= kth)
 {
  del_kth(kth, n1, l, m); 
 }else 
 {
  del_kth(kth-seg[n1], n2, m+1, r);
 }
 seg[node] = seg[n1] + seg[n2]; 
}
int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
  {
   int x;
   scanf("%d", &x);
   upd(x, 1); 
  }
  
  while(q--)
  {
  int k;scanf("%d", &k);
  if (k > 0)
   upd(k, 1); 
  else 
   del_kth(-k); 
 }
  bool emp = 1;
  for (int i = 0; i < N; i++)
  {
   if (ans[i])
   {
    printf("%d ", i); 
    emp = 0;
    break; 
   }
  }
  if (emp)printf("0");
  printf("\n");  
  
}
