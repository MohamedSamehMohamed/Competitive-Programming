// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
void test()
{
 scanf("%d", &n);
 for (int i = 0, x; i < n; i++)
 {
  scanf("%d", &x);
  pq.push(x); 
 }
 long long ans = 0;
 while(pq.size() > 2)
 {
  pq.pop();
  pq.pop();
  ans += pq.top();
  pq.pop();
 }
 while(!pq.empty())pq.pop();
 printf("%lld\n", ans);
}
int main()
{
 test();
}
