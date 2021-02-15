// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, mod, d; 
struct Matrix
{
 int row, col; 
 int a[16][16]; 
 Matrix (int r, int c)
 {
  row = r;
  col = c; 
  for (int i = 0; i < row; i++)
   for (int j = 0; j < col; j++)
    a[i][j] = 0;
 }
 Matrix operator *(const Matrix& other)
 {
  Matrix ret(row, other.col); 
  for (int i = 0; i < row; i++)
   for (int j = 0; j < col; j++)
    for (int k = 0; k < ret.col; k++)
     ret.a[i][k] = (1LL*ret.a[i][k] + 1LL*a[i][j] * other.a[j][k])%mod;
  return ret; 
 }
};
int A[16], F[16];
Matrix power(Matrix& mat, int p)
{
 Matrix ret(1, d);
 for (int i = 0; i < d; i++)
  ret.a[0][i] = F[i];
 while(p > 0)
 {
  if (p & 1) ret = ret * mat; 
  mat = mat * mat; 
  p >>= 1;  
 }
 return ret; 
}
int main()
{ 
 while(scanf("%d%d%d", &d, &n, &mod) && (d+n+mod != 0))
 {
  for (int i = 0; i < d; i++) scanf("%d", A+i);
  for (int i = 0; i < d; i++) scanf("%d", F+i); 
  Matrix mat(d, d); 
  for (int j = 0; j < d-1; j++) mat.a[j+1][j] = 1;
  for (int i = 0; i < d; i++) mat.a[i][d-1] = A[d-i-1];
  Matrix ret = power(mat, n-d); 
  printf("%d\n", ret.a[0][d-1]);
 }
}
/*
a b c 
newA = 0 * a + 1 * b + 0 * c 
newB = 0 * a + 0 * b + 1 * c 
newC = 1 * a * a1 + 1 * b * b1 + 1 * c * c1  
 
 [f1 f2 f3]    0 0 a1
               1 0 a2
               0 1 a3

*/
