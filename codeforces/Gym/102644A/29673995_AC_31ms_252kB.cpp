// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
struct Matrix
{
 const static int sz = 2; 
 double a[sz][sz]; 
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
     ret.a[i][k] += a[i][j] * other.a[j][k];
  return ret; 
 }
 void Identity()
 {
  for (int i = 0; i < sz; i++)
   for (int j = 0; j < sz; j++)
    a[i][j] = (i == j); 
 }
};
int n;
double p; 
/*
n =0
H = 1, S = 0

n = 1 
newH = H * (1-p) + S * p
newS = H * p + S * (1-p)
*/
int main()
{
 scanf("%d%lf", &n, &p);
 Matrix ret;
 ret.Identity(); 
 Matrix mat;
 mat.a[0][0] = 1-p;
 mat.a[0][1] = p;
 mat.a[1][0] = p;
 mat.a[1][1] = 1-p;
 while(n)
 {
  if (n&1)ret = ret * mat; 
  mat = mat * mat; 
  n >>= 1; 
 }
 printf("%.9lf\n", ret.a[0][0]); 
}
