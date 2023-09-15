// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 404;
int n, a[N], dp[N][N], vis[N][N], id;
int solve(int cur = 1, int i = 0)
{
 if (i == n)return 0;
 if (cur >= N)return 1e9;
 int &ret = dp[cur][i];
 if (vis[cur][i] == id)return ret; 
 vis[cur][i] = id;
 ret = abs(a[i] - cur) + solve(cur+1, i+1);
 if (cur <= a[i])
  ret = min(ret, solve(cur+1, i)); 
 return ret;
}
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i);
 sort(a, a+n);
 id++;
 printf("%d\n", solve()); 
}
int main()
{
  int t; 
  scanf("%d", &t);
  while(t--)
   test();
}
