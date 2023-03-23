// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int p[N], a[N][2], n, m; 
set<int> st[3];
map<int, bool> mp; 
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", p+i);
 for (int i = 0; i < n; i++)scanf("%d", a[i]); 
 for (int i = 0; i < n; i++)scanf("%d", a[i]+1); 
 for (int i = 0; i < n; i++)
 {
  a[i][0]--;a[i][1]--;
  st[a[i][0]].insert(p[i]);
  st[a[i][1]].insert(p[i]);
 }
 scanf("%d", &m);
 for (int i = 0; i < m; i++)
 {
  int c;scanf("%d", &c);c--;
  int ans = -1;
  while(!st[c].empty() && mp.find(*st[c].begin()) != mp.end())
   st[c].erase(st[c].begin());
  if (!st[c].empty())
  {
   ans = *st[c].begin();
   st[c].erase(st[c].begin()); 
  }
  mp[ans] = 1; 
  printf("%d%c", ans, (i+1==m? '\n': ' ')); 
 }
}
