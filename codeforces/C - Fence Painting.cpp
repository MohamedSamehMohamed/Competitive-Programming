// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, m, a[N], b[N], c[N]; 
queue<int> q[N], Free[N]; 
int ans[N]; 
void test()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i <= n; i++)while(!q[i].empty())q[i].pop(); 
 for (int i = 0; i <= n; i++)while(!Free[i].empty())Free[i].pop(); 
 for (int i = 0; i < n; i++) scanf("%d", a+i); 
 for (int i = 0; i < n; i++) scanf("%d", b+i); 
 for (int i = 0; i < m; i++) scanf("%d", c+i);
  for (int i = 0; i < n; i++)
  {
   if (a[i] != b[i])
   {
    q[b[i]].push(i); 
   }else 
   Free[b[i]].push(i); 
  }
  for (int i = 0; i < m; i++)ans[i] = -1; 
  int lst = -1; 
  bool can = 1; 
  for (int i = m-1; i >= 0; i--)
  {
   if (!q[c[i]].empty())
   {
    // painter i will paint q[c[i]].front()
    ans[i] = q[c[i]].front();
    lst = q[c[i]].front(); 
    q[c[i]].pop(); 
   }else 
   {
    if (lst != -1)
    {
     ans[i] = lst; 
    }else 
    {
     if (!Free[c[i]].empty())
     {
      ans[i] = Free[c[i]].front();
      Free[c[i]].pop(); 
      lst = ans[i]; 
      continue; 
     }
     can = 0;
     break; 
    }
   }
  }
  for (int i = 0; i <= n; i++)
   can &= (q[i].empty()); 
  if (can)
  {
   printf("YES\n"); 
   for (int i = 0; i < m; i++)
    printf("%d%c", ans[i]+1, (i+1==m? '\n': ' ')); 
   return; 
  }
  printf("NO\n"); 
  return; 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
