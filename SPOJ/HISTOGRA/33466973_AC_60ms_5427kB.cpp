#include <bits/stdc++.h>
using namespace std;
void read_file(){
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9;
int a[N], n;
long long ans;
int cnt[N]; 
void solve()
{
  stack<int> stk;
  for(int i = 0; i < n; i++)
  {
    while (!stk.empty() && a[stk.top()] >= a[i])
      stk.pop(); 
    int len = i - (stk.empty()? 0: stk.top()) + 1; 
    cnt[i] = i - (stk.empty()? 0: stk.top() + 1);
    ans = max(ans, 1LL * len * (stk.empty()? a[i]: a[stk.top()]));
    stk.push(i); 
  }
  while(!stk.empty())stk.pop(); 
  reverse(a, a+n);
  reverse(cnt, cnt+ n);
  for(int i = 0; i < n; i++)
  {
    while (!stk.empty() && a[stk.top()] >= a[i])
      stk.pop(); 
    cnt[i] += i - (stk.empty()? 0: stk.top() + 1);
    stk.push(i);
    ans = max(ans, 1LL * a[i] * (cnt[i] + 1)); 
  }
  reverse(a, a+n); 
}
int main()
{
  read_file();
  while(scanf("%d", &n) && n)
  {
    for(int i = 0; i < n; i++)
      scanf("%d", a+i); 
    ans = 0;
    solve();
    reverse(a, a+n); 
    solve(); 
    printf("%lld\n", ans); 
  }
}
