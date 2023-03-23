// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int N, S, Q; 
void test()
{
 scanf("%d%d%d", &N, &S, &Q); 
 stack<int> stk; 
 queue<int> q[N]; 
 int ans = -2;
 int cnt = 0;
 for (int i = 0; i < N; i++)
 {
  int sz, idx;scanf("%d", &sz); 
  cnt += sz; 
  while(sz--)
  {
   scanf("%d", &idx);idx--;
   q[i].push(idx); 
  }
 }
 
 for (int i = 0; cnt;i=(i+1)%N)
 {
  ans += 2; 
  while(!stk.empty())
  {
   int cur = stk.top();
   stk.pop();
   ans++; 
   if (cur == i)
   {
    cnt--; 
    continue; 
   }
   if (q[i].size() < Q)
    q[i].push(cur); 
   else 
   {
    ans--; 
    stk.push(cur);
    break; 
   }
  }
  while(stk.size() < S && !q[i].empty()) stk.push(q[i].front()), q[i].pop(), ans++; 
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
