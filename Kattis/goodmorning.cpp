// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
string keyboard[] = {"123", "456", "789", "#0#"};
int dp[4][3][10], reach[201];
pair<int, int> getPos(int num)
{
 for (int i = 0; i < 4; i++)
  for (int j = 0; j < 3; j++)
   if (keyboard[i][j] == num + '0')
    return {i, j};
 return {-1, -1}; 
}
bool valid(int dx, int dy)
{
 return min(dx, dy) >= 0 && dx < 4 && dy < 3; 
}
bool can(int dx, int dy, int digit)
{
 if (!valid(dx, dy))return 0;
 if (keyboard[dx][dy] == digit + '0')return 1; 
 int &ret = dp[dx][dy][digit];
 if (~ret)return ret;
 return ret = max(can(dx+1, dy, digit), can(dx, dy+1, digit)); 
}
bool solve(int x)
{
 stack<int> digs;
 while(x)
 {
  digs.push(x%10);
  x/=10; 
 }
 int dx = 0, dy = 0;
 while(!digs.empty())
 {
  int cur = digs.top();
  digs.pop();
  if (!can(dx, dy, cur))return 0;
  tie(dx, dy) = getPos(cur); 
 }
 return 1; 
}
int n; 
void test()
{
 scanf("%d", &n);
 int l, r;
 l = r = n;
 while(!reach[r])r++;
 while(!reach[l])l--; 
 printf("%d\n", (n-l < r-n? l: r)); 
}
int main()
{
 memset(dp, -1, sizeof dp);
 for (int i = 1; i <= 200; i++)
  reach[i] = solve(i); 
 
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
