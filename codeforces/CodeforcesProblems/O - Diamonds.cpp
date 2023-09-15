#include <bits/stdc++.h>
 
using namespace std;
const int N = 300; 
int n; 
float a[300][2]; 
int dp[N][N]; 
int vis[N][N], id; 
int solve(int i, int lst)
{
 if (i == n)
  return 0; 
 int &ret = dp[i][lst];
 if (vis[i][lst] == id)return ret; 
 vis[i][lst] = id; 
 ret = solve(i+1, lst);
 if (a[i][0] > a[lst][0] && a[i][1] < a[lst][1])
  ret = max(ret, 1 + solve(i+1, i)); 
 return ret; 
}
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  scanf("%f%f", a[i], a[i]+1); 
 }
 id++; 
 int ans = 1;
 for (int i = 0; i < n; i++)
  for (int j = i+1; j < n; j++)
   if (a[j][0] > a[i][0] && a[j][1] < a[i][1])
    ans = max(ans, 1 + solve(j, i)); 
 printf("%d\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
 {
  test();
 }
}
