// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 104;
char x[N][N];
string pat = "ICPCASIASG";  
int n;
// (a−c)^2+(b−d)^2=5.
bool valid(int a, int b)
{
 return min(a, b) >= 0 && max(a, b) < n; 
}
bool ok(int a, int b, int c, int d)
{
 if (!valid(c, d))return 0;
 a++;b++;c++;d++;
 return (a-c)*(a-c) + (b-d)*(b-d) == 5; 
}
bool BFS(int stx, int sty)
{
 queue<pair<int,int>> q;
 q.push({stx, sty});
 int idx = 0;  
 while(!q.empty())
 {
  int sz = q.size();
  idx++;
  if (idx == pat.size())return 1; 
  while(sz--)
  {
   auto cur = q.front();
   q.pop();
   for (int i = -3; i <= 3; i++)
    for (int j = -3; j <= 3; j++)
    {
     int nx = cur.first + i;
     int ny = cur.second + j;
     if (ok(cur.first, cur.second, nx, ny) && x[nx][ny] == pat[idx])
     {
      q.push({nx, ny}); 
     }
    }
  }
 }
 return 0; 
}
bool can()
{
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
   if (x[i][j]=='I' && BFS(i, j))
    return 1; 
 return 0; 
}
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
   scanf(" %c", &x[i][j]);
 printf("%s\n", (can()? "YES": "NO")); 
}
