#include<bits/stdc++.h>
using namespace std;
int n; 
void test()
{
 scanf("%d", &n);
 map<int, int> mp;
 for (int i = 0; i < n; i++)
 {
  int x;scanf("%d", &x); 
  mp[x]++; 
 }
 priority_queue<int> pq;
 for (auto i: mp)pq.push(i.second); 
 while(pq.size() > 1)
 {
  int c = pq.top();pq.pop();
  int c1 = pq.top();pq.pop(); 
  c--;c1--;
  if (c)pq.push(c);
  if (c1)pq.push(c1); 
 }
 int ans = (pq.empty()? 0: pq.top()); 
 printf("%d\n", ans); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
