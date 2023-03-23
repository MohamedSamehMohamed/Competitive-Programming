// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7; 
struct Matrix
{
 int sz;
 vector<vector<int>> a;
 Matrix (int sz)
 {
  this->sz = sz; 
  a = vector<vector<int>>(sz, vector<int>(sz));
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = 0;
 }
 Matrix operator *(const Matrix& other)
 {
  Matrix ret(sz); 
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    for (int k = 0; k < sz; k++)
     ret.a[i][k] = (ret.a[i][k] + 1LL*a[i][j] * other.a[j][k])%mod;
  return ret; 
 }
 void Identity()
 {
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = (i == j); 
 }
};
int n, m, k;
int main()
{ 
 scanf("%d%d%d", &n, &m, &k);
 Matrix mat(n), ret(n); 
 ret.Identity(); 
 for (int i = 0; i < m; i++)
 {
  int u, v;
  scanf("%d%d", &u, &v);
  u--;v--;
  mat.a[u][v] = 1; 
 } 
 while(k)
 {
  if (k & 1) ret = ret * mat; 
  mat = mat * mat; 
  k >>= 1LL; 
 }
 int ans = 0; 
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
   ans = (ans + ret.a[i][j]) % mod; 
 printf("%d\n", ans);
}
