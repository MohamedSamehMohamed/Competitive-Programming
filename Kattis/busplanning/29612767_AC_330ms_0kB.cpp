// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 17;
int n, k, c; 
int bad[N][N], good[1<<N], dp[1<<N], tem[N]; 
map<string, int> mp1;
map<int, string> mp2;
int getInt(string x)
{
 if (mp1.find(x) != mp1.end())return mp1[x]; 
 int sz = mp1.size();
 mp1[x] = sz;
 mp2[sz] = x;  
 return sz; 
}
string getStr(int x)
{
 return mp2[x]; 
}
int solve(int msk = (1<<n)-1)
{
 if (!msk)return 0;
 int &ret = dp[msk];
 if (~ret)return ret; 
 ret = n; 
 for (int curmsk = msk; curmsk; curmsk = (curmsk-1)&msk)
  if (good[curmsk])
   ret = min(ret, 1 + solve(msk^curmsk)); 
 return ret; 
}
void print(int msk)
{
 for (int i = 0, f = 1; i < n; i++)
 {
  if (msk & (1<<i))
  {
   if (!f)printf(" "); 
   f = 0; 
   printf("%s", getStr(i).c_str()); 
  }
 }
 printf("\n"); 
}
void build(int msk = (1<<n)-1)
{
 if (!msk)return;
 int best = dp[msk];
 for (int curmsk = msk; curmsk; curmsk = (curmsk-1)&msk)
  if (good[curmsk])
  {
   if (best == 1 + solve(msk^curmsk))
   {
    print(curmsk);
    build(msk^curmsk);
    break; 
   }
  }
}
int main()
{
 memset(dp, -1, sizeof dp); 
 scanf("%d%d%d", &n, &k, &c);
 for (int i = 0; i < n; i++)
 {
  char x[12]; 
  scanf(" %s", x);
  string str = x; 
  getInt(str); 
 }
 for (int i = 0; i < k; i++)
 {
  char x[12], y[12]; 
  scanf(" %s %s", x, y);
  string s1 = x, s2 = y;
  int u = getInt(s1);
  int v = getInt(s2);
  bad[u][v] = bad[v][u] = 1; 
 }
 for (int i = 0; i < 1<<n; i++)
 {
  int sz = 0;
  for (int j = 0; j < n; j++)
  {
   if (i & (1<<j))
    tem[sz++] = j; 
  }
  good[i] = (sz<=c); 
  for (int j = 0; j < sz; j++)
   for (int k = j+1; k < sz; k++)
    good[i] &= (!bad[tem[j]][tem[k]]);
 }
 printf("%d\n", solve()); 
 build(); 
}
