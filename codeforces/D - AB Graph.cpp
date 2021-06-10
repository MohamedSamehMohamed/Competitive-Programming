// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n, m;
char x[N]; 
int mat[N][N];
int dp[N][2];
// dp[i][0] -> next a
// dp[i][1] -> next b   
void solve(int u)
{
 if (~dp[u][0])return; 
 for (int i = 0; i < 2; i++)dp[u][i] = 0;
 for (int i = 0; i < n; i++)
 {
  if (i == u)continue; 
  solve(i);
  dp[u][mat[u][i]] = i+1;
 }
}
void test()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i <= n; i++)
  for (int j = 0; j < 2; j++)
    dp[i][j] = -1; 
 for (int i = 0; i < n; i++)
 {
  scanf(" %s", x);
  for (int j = 0; j < n; j++)
   mat[i][j] = (x[j] == 'a'? 0: 1);
 }
 if (m == 1)
 {
  printf("YES\n1 2\n");
  return;
 }
 int U, V;
 U = V = -1;
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
  {
   if (i != j && mat[i][j] == mat[j][i])
   {
    U = i;
    V = j; 
   }
  }
 if (m&1)U = 0, V = 1; 
 if (~U)
 {
  printf("YES\n"); 
  for (int i = 0; i <= m; i++, swap(U, V))
  {
   printf("%d%c", U+1, (i==m? '\n': ' ')); 
  }
  return; 
 }
 int x, y, z; 
  x = y = z = -1; 
  for (int i = 0; x == -1 && i < n; i++)
   for (int j = 0; j < n; j++)
   {
    if (i == j)continue; 
    solve(j);
    if (dp[j][mat[i][j]])
    {
     x = i;
     y = j;
     z = dp[j][mat[i][j]]-1;
     break; 
    }
   }
  if (x == -1)
  {
   printf("NO\n");
   return; 
  }
 queue<int> ans;
 if (m % 4 == 0)
 {
  ans.push(y);
  while(ans.size() <= m)
  {
   ans.push(z);
   ans.push(y); 
   ans.push(x);
   ans.push(y); 
  }
 }else 
 {
  ans.push(x); 
  while(ans.size() <= m)
  {
   ans.push(y); 
   ans.push(z); 
   ans.push(y); 
   ans.push(x); 
  }
 }
 printf("YES\n");
 printf("%d", ans.front() + 1);
 ans.pop(); 
 while(m--)
 {
  printf(" %d", ans.front()+1);
  ans.pop(); 
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
