#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n, L, R; 
 scanf("%d%d%d", &n, &L, &R);
 vector<int> v(n+1); 
 vector<long long> pre(n+1);
 pre[0] = 0; 
 for (int i = 1; i <= n; i++)
 {
  scanf("%d", &v[i]); 
  pre[i] = pre[i-1] + v[i]; 
 }
 deque<int> dq; 
 int l = 0, r = -1;
 long long mx = -1e18; 
 for (int i = 1; i <= n; i++)
 {
  int nl = i - R; 
  int nr = i - L; 
  while(r < nr) 
  {
   r++; 
   while(!dq.empty() && pre[dq.back()] >= pre[r]) dq.pop_back(); 
   dq.push_back(r); 
  }
  while(l < nl)
  {
   while(!dq.empty() && dq.front() <= l)dq.pop_front(); 
   l++;
  }
  if (!dq.empty())
  mx = max(mx, pre[i] - pre[dq.front()]); 
 }
 printf("%lld\n", mx); 
}
