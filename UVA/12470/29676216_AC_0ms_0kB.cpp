// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long n;
int mod = 1e9 + 9; 
struct Matrix
{
 int row, col; 
 int a[3][3]; 
 Matrix (int r = 3, int c = 3)
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
  for (int i = 0; i < ret.row; i++)
   for (int j = 0; j < col; j++)
    for (int k = 0; k < ret.col; k++)
     ret.a[i][k] = (ret.a[i][k] + 1LL*a[i][j] * other.a[j][k])%mod;
  return ret; 
 }
 void Identity()
 {
  for (int i = 0; i < row; i++)
   for (int j = 0; j < col; j++)
    a[i][j] = (i == j); 
 }
};
void PrintMat(Matrix mat)
{
 for (int i = 0; i < mat.row; i++)
  for (int j = 0; j < mat.col; j++)
   cout << mat.a[i][j] <<" \n"[j + 1== mat.col]; 
 cout <<"\n";
}
Matrix power(Matrix mat, long long p)
{
 Matrix ret(1, 3);
 ret.a[0][0] = 0;
 ret.a[0][1] = 1;
 ret.a[0][2] = 2;
 while(p > 0)
 {
  if (p & 1) ret = ret * mat; 
  mat = mat * mat; 
  p >>= 1LL; 
 }
 return ret; 
}
int main()
{ 
 /*
 [0 1 2] * [0 0 1]
           [1 0 1]
           [0 1 1]
 [1 2 3]
 [2 3 6]
 a = 0, b = 1, c = 2
 for (int i = 4; i <= n; i++)
 {
  newA = 0*a + 1*b + 0*c
  newB = 0*a + 0*b + 1*c
  newC = 1*a + 1*b + 1*c
 }
        
 */
 int coffe[3][3] = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
 Matrix mat(3, 3);
 for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
   mat.a[i][j] = coffe[i][j];
 while(scanf("%lld", &n) && n)
 { 
  if (n <= 3)
  {
   printf("%d\n", (int)n-1); 
   continue; 
  }
  Matrix ret = power(mat, n-1); 
  printf("%d\n", ret.a[0][0]);
 }
}
