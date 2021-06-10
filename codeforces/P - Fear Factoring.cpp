#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+2 ; 
int siev[N];
long long ans[N]; 
long long a, b; 
long long get(int p)
{
 long long l = 1, r = 1e12, m, ans = -1;
 while(l <= r)
 {
  m = (l+r)>>1LL; 
  if (m * p >= a)
  {
   ans = m * p; 
   r = m-1; 
  }else 
  l = m+1; 
 }
 return ans; 
}
int main()
{
 
 cin >> a >> b; 
 for (int i = 2; i < N; i++)
 {
  long long cur = get(i);
  while(cur <= b)
  { 
  // cout << cur << ' ' << i << '\n'; 
   ans[cur-a] += i; 
   if (cur/i >= N)
    ans[cur-a] += cur/i; 
   cur += i; 
  }
 }
 long long sum = 0; 
 for (int i = 0; i <= b-a; i++)
 {
  if (i + a != 1 && i + a >= N)ans[i] += i + a; 
  sum += ans[i]; 
  sum++; 
 }
 cout << sum << '\n';
 
}
