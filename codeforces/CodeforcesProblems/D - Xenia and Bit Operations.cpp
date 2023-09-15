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
using namespace std ;
const int N = (1<<18), M = 30; 
int n, m, a[N], seg[4*N], pos, val;
int cal(int op1, int v1, int v2)
{
 return op1? v1|v2: v1^v2;
}
void build(int node = 0, int l = 0, int r = (1<<n)-1, int op1 = n % 2)
{
 if (l == r)
 {
  seg[node] = a[l];
  return;
 }
 int m = (l+r)>>1;
 build(node * 2 + 1, l, m, op1^1);
 build(node * 2 + 2, m+1, r, op1^1);
 seg[node] = cal(op1, seg[node*2+1], seg[node*2+2]);
}
void update(int node = 0, int l = 0, int r = (1<<n)-1, int op1 = n % 2)
{
 if (l > pos|| r < pos)return;
 if (l == r)
 {
  seg[node] = val;
  return;
 }
 int m = (l+r)>>1;
 update(node * 2 + 1, l, m, op1^1);
 update(node * 2 + 2, m+1, r, op1^1);
 seg[node] = cal(op1, seg[node*2+1], seg[node*2+2]);
}
int main()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i < (1<<n); i++)
  scanf("%d", a+i);
 build(); 
 while(m--)
 {
  scanf("%d%d", &pos, &val);
  pos--;
  update();
  int ans = seg[0];
  printf("%d\n", ans);
 }
}
