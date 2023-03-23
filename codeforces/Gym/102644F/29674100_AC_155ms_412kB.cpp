// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long INF = 3e18, MX = 1e18; 
int n, m, k;
struct Matrix
{
 int sz;
 vector<vector<long long>> a;
 Matrix (int sz)
 {
  this->sz = sz; 
  a = vector<vector<long long>>(sz, vector<long long>(sz));
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = 0;
 }
 Matrix operator *(const Matrix& other)
 {
  Matrix ret(sz); 
  ret.Set(INF); 
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    for (int k = 0; k < sz; k++)
     ret.a[i][k] = min(ret.a[i][k], a[i][j] + other.a[j][k]);
  return ret; 
 }
 void Identity()
 {
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = (i == j? 0: INF); 
 }
 void Set(long long val)
 {
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = val;
 }
};
int main()
{ 
 scanf("%d%d%d", &n, &m, &k);
 Matrix ret(n), mat(n); 
 ret.Identity(); 
 mat.Set(INF); 
 for (int i = 0; i < m; i++)
 {
  int u, v, c;
  scanf("%d%d%d", &u, &v, &c);
  u--;v--;
  mat.a[u][v] = min(1LL*c, mat.a[u][v]); 
 }
 while(k)
 {
  if (k & 1) ret = ret * mat; 
  mat = mat * mat; 
  k >>= 1LL; 
 }
 
 long long ans = INF;  
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    ans = min(ans, ret.a[i][j]); 
 if (ans > MX)
  printf("IMPOSSIBLE\n"); 
 else 
  printf("%lld\n", ans);
}
