// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N], n;
long long pre[N], tem[N]; 
void addRange(int l, int r, int st, int add)
{
 pre[l] += st;
 pre[r+1] -= st + (r-l)*add;
 tem[l+1] += add;
 tem[r+1] -= add;  
}
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++) scanf("%d", a+i); 
 map<int, int> frq, frq1;
 for (int i = 0; i < n; i++)frq[a[i]]++;
 for (int i = 0; i < n; i++)frq1[frq[a[i]]]++;  
 for (int i = 0; i <= n; i++)pre[i] = tem[i] = 0;  
 set<int> tk;
 for (int i = 0; i < n; i++)
 {
  if (tk.find(a[i]) == tk.end())
  {
   int c = frq[a[i]]; 
   addRange(0, c-1, c, -1); 
   tk.insert(a[i]); 
  }
 }
 int cur = tem[0];
 for (int i = 1; i <= n; i++)
 {
  cur += tem[i]; 
  pre[i]+= pre[i-1] + cur; 
 }
 int ans = n;
 int prv = 0;
 for (int i = 1; i <= n; i++)
 {
  ans = min(1LL*ans, prv + pre[i]);
  prv += frq1[i]; 
 }
 printf("%d\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
