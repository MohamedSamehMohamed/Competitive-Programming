// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, mod = 1e9, d; 
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
 int t; scanf("%d", &t); 
 while(t--)
 {
  scanf("%d", &d); 
  for (int i = 0; i < d; i++) scanf("%d", F+i);
  for (int i = 0; i < d; i++) scanf("%d", A+i);
  scanf("%d", &n);  
  Matrix mat(d, d); 
  for (int j = 0; j < d-1; j++) mat.a[j+1][j] = 1;
  for (int i = 0; i < d; i++) mat.a[i][d-1] = A[d-i-1];
  Matrix ret = power(mat, n-d); 
  int idx = (n <= d? n-1: d-1);
  printf("%d\n", ret.a[0][idx]);
 }
}


n =0
H = 1, S = 0
 
n = 1 
newH = H * (1-p) + S * p
newS = H * p + S * (1-p)

n = 2
newH1 = newH * (1-p) + newS * p
newH1 = H *(1-p)^2 + H * p^2 + p * S * (1-p)
newS1 =  
