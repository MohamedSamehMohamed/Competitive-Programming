#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9; 
vector<int> adj[26]; 
char x[N];
void test()
{
 scanf(" %s", x); 
 int n = strlen(x);
 for (int i = 0; i < 26; i++)adj[i].clear(); 
 for (int i = 0; i < n; i++)
  adj[x[i]-'a'].push_back(i); 
 int cur = 0;
 int sz = 0;
 for (int i = 0; i < 26; i++)sz += (adj[i].size() > 0);
 string ans = "";
 while(sz--)
 {
  for (int i = 25; i >= 0; i--)
  {
   if (adj[i].empty())continue; 
   int idx = *lower_bound(adj[i].begin(), adj[i].end(), cur); 
   bool can = 1; 
   for (int j = 0; j < 26; j++)
    if (!adj[j].empty() && adj[j].back() < idx)
    {
     can = 0;
     break; 
    }
   if (can)
   {
    ans += char('a' + i); 
    adj[i].clear(); 
    cur = idx; 
    break; 
   }
  }
 }
 printf("%s\n", ans.c_str()); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)test(); 
}
