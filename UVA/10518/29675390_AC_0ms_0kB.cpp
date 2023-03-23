// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long n;
int mod; 
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
 for (int i = 0; i < 3; i++)ret.a[0][i] = 1;  
 while(p)
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
 int a = 1, b = 1;
 for (int i = 2; i < 20; i++)
 {
  int newA = 0*a + 1*b + 0*c; 
  int newB = 1*a + 1*b + 1*c;
  int newC = 0*a + 0*b + 1*c;
  a = newA;
  b = newB; 
 }
 [1 1 1][0 1 0]
        [1 1 0]
        [0 1 1]
 */
 int coffe[3][3] = {{0, 1, 0}, {1, 1, 0}, {0, 1, 1}};
 Matrix mat(3, 3);
 for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
   mat.a[i][j] = coffe[i][j];
 int C = 0; 
 while(scanf("%lld%d", &n, &mod) && (n+mod != 0))
 {
  
  Matrix ret = power(mat, n); 
  printf("Case %d: %lld %d %d\n", ++C, n, mod, ret.a[0][0]);
 }
}
