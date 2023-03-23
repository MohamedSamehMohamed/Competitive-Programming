// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7; 
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b)
{
 vector<vector<int>> ret(a.size(), vector<int>(b[0].size()));
 for (int i = 0; i < a.size(); i++)
  for (int j = 0; j < a[i].size(); j++)
   for (int k = 0; k < a.size(); k++)
    ret[i][k] = (ret[i][k] + (1LL*a[i][j] * b[j][k]) % mod) % mod;
 return ret; 
}
int n, m, k; 
int main()
{ 
 scanf("%d%d%d", &n, &m, &k);
 vector<vector<int>> mat(n, vector<int>(n)), ret(n, vector<int>(n));
 for (int i = 0; i < n; i++) ret[i][i] = 1;
 for (int i = 0; i < m; i++)
 {
  int u, v;
  scanf("%d%d", &u, &v);
  u--;v--;
  mat[u][v] = 1; 
 } 
 while(k)
 {
  if (k & 1) ret = mul(ret, mat); 
  mat = mul(mat, mat); 
  k >>= 1LL; 
 }
 int ans = 0; 
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
   ans = (ans + ret[i][j]) % mod; 
 printf("%d\n", ans);
}
