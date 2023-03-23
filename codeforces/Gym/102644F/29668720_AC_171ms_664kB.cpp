// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
long long INF = 3e18, MX = 1e18; 
int n, m, k;
vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b)
{
 vector<vector<long long>> ret(a.size(), vector<long long>(b[0].size()));
 for (int i = 0; i < a.size(); i++)
  for (int j = 0; j < a.size(); j++)
   ret[i][j] = INF;
 
 for (int i = 0; i < a.size(); i++)
  for (int j = 0; j < a[i].size(); j++)
   for (int k = 0; k < a.size(); k++)
    ret[i][k] = min(ret[i][k] , a[i][j] + b[j][k]); 
   
 return ret;
}
int main()
{ 
 scanf("%d%d%d", &n, &m, &k);
 vector<vector<long long>> mat(n, vector<long long>(n)), ret(n, vector<long long>(n));
 for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ret[i][j] = (i==j?0:INF), mat[i][j] = INF; 
 for (int i = 0; i < m; i++)
 {
  int u, v, c;
  scanf("%d%d%d", &u, &v, &c);
  u--;v--;
  mat[u][v] = min(1LL*c, mat[u][v]); 
 }
 while(k)
 {
  if (k & 1) ret = mul(ret, mat); 
  mat = mul(mat, mat); 
  k >>= 1LL; 
 }
 
 long long ans = INF;  
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    ans = min(ans, ret[i][j]); 
 if (ans > MX)
  printf("IMPOSSIBLE\n"); 
 else 
  printf("%lld\n", ans);
}
