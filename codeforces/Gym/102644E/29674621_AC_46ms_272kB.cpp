// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1LL << 32; 
struct Matrix
{
 int sz;
 vector<vector<unsigned long long>> a;
 Matrix (int sz)
 {
  this->sz = sz; 
  a = vector<vector<unsigned long long>>(sz, vector<unsigned long long>(sz));
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
void build(Matrix& mat)
{
 int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
 int dy[] = {-1, 1, -2, 2, 1, -1, 2, -2}; 
 mat.a[64][64] = 1; 
 for (int i = 0; i < 8; i++)
   for (int j = 0; j < 8; j++)
    for (int k = 0; k < 8; k++)
     {
      int nx = dx[k] + i;
      int ny = dy[k] + j;
      if (min(nx, ny) < 0 || max(nx, ny) >= 8)continue; 
      int st = i * 8 + j; 
      int en = nx * 8 + ny;
      mat.a[st][en] = mat.a[en][st] = 1; 
      mat.a[st][64] = 1; 
     }
}
Matrix fastPower(Matrix& mat, int n)
{
 Matrix ret(65);
 ret.Identity();
 while(n)
 {
  if (n & 1) ret = ret * mat; 
  mat = mat * mat;  
  n >>= 1LL; 
 }
 return ret;
}
int main()
{
 int n; 
 scanf("%d", &n);
 Matrix mat(65);
 build(mat); 
 n++;
 Matrix ret = fastPower(mat, n);
 unsigned long long ans = ret.a[0][64]; 
 printf("%llu\n", ans);
}
