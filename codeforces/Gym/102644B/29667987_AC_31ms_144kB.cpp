// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7; 
long long n;
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b)
{
 vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));
 for (int i = 0; i < a.size(); i++)
  for (int j = 0; j < a[i].size(); j++)
   for (int k = 0; k < a.size(); k++)
    ret[i][k] = (ret[i][k] + (1LL*a[i][j] * b[j][k]) % mod) % mod;
 return ret; 
}
int main()
{ 
 scanf("%lld", &n);
 vector<vector<int>> mat(2, vector<int>(2)), ret(2, vector<int>(2));
 mat[0][0] = 19;
 mat[0][1] = 7;
 mat[1][0] = 6;
 mat[1][1] = 20;
 ret[0][0] = ret[1][1] = 1; 
 while(n)
 {
  if (n & 1) ret = mul(ret, mat); 
  mat = mul(mat, mat); 
  n >>= 1LL; 
 }
 printf("%d\n", ret[0][0]);
}
