// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7; 
long long n;
struct Matrix
{
 const static int sz = 2; 
 int a[sz][sz]; 
 Matrix ()
 {
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = 0;
 }
 Matrix operator *(const Matrix& other)
 {
  Matrix ret; 
  for (int i = 0; i < 2; i++)
   for (int j = 0; j < 2; j++)
    for (int k = 0; k < 2; k++)
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
int main()
{ 
 scanf("%lld", &n);
 Matrix mat, ret;
 ret.Identity(); 
 mat.a[0][0] = 19;
 mat.a[0][1] = 7;
 mat.a[1][0] = 6;
 mat.a[1][1] = 20;
 while(n)
 {
  if (n & 1) ret = ret * mat; 
  mat = mat * mat; 
  n >>= 1LL; 
 }
 printf("%d\n", ret.a[0][0]);
}
