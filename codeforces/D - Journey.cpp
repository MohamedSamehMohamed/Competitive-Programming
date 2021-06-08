// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
char x[N];
int dp[N][2][2], id, vis[N][2][2], n; 
char y[2] = {'L', 'R'}; 
int solve(int i, int st, int dir)
{
 if (i >= n && dir)return 1;
 if (i - 1 < 0 && !dir)return 1;
 int &ret = dp[i][st][dir];
 if (vis[i][st][dir] == id)return ret;
 vis[i][st][dir] = id;  
 if (dir)
  ret = (x[i] == y[st]? 1 + solve(i+1, st^1, dir): 1);
 else
  ret = (x[i-1] == y[st]? 1 + solve(i-1, st^1, dir): 1);
 return ret;
}
void test()
{
 scanf("%d", &n);
 scanf(" %s", x); 
 id++;
 for (int i = 0; i <= n; i++)
 {
  printf("%d ", solve(i, 0, 0) + solve(i, 1, 1) - 1);
 }
 printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
   test();
   
}
