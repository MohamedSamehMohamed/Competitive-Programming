// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int frq[N];
long long dp[N]; 
// dp[i] -> number of subsets of length 4 that have a common divisor i
int n;
long long NcK(int N, int K)
{
 if (N < 4)return 0;
 long long ret = 1;
 for (int i = K+1; i <= N; i++)
  ret = (ret * i)/(i-K); 
 return ret; 
} 
int main()
{
 while(~scanf("%d", &n))
 {
  memset(frq, 0, sizeof frq);
  int x;
  while(n--)
  {
   scanf("%d", &x); 
   frq[x]++; 
  } 
  for (int i = N-1; i >= 1; i--)
  {
   int cnt = 0;
   long long dup = 0;
   dp[i] = 0;
   for (int j = i; j < N; j += i)
    cnt += frq[j], dup += dp[j];   
   dp[i] = NcK(cnt, 4) - dup; 
  }
  printf("%lld\n", dp[1]); 
 }
}
