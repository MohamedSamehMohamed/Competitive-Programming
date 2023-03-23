// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, k;
char x[N];
int pre[N]; 
void test()
{
 scanf("%d%d %s", &n, &k, x);
 pre[0] = 0;
 for (int i = 1; i <= n; i++)
 {
  pre[i] = (x[i-1] == '1');
  pre[i] += pre[i-1];
 }
 long long tot = 1LL * n * n;
 long long ans = 0; 
 for (int i = 1; i <= n; i++)
 {
  if (x[i-1] == '0')continue; 
  ans++;  
  int r = min(n, i + k); 
  ans += 2LL * (pre[r] - pre[i]);
 }
 if (!ans) tot = 1; 
 long long g = __gcd(tot, ans);
 ans/= g;
 tot/=g;
 printf("%lld/%lld\n", ans, tot); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
