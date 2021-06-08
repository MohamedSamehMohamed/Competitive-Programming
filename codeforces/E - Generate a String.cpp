// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
long long dp[N];
int n, x, y;  
int main()
{
 // dp[i] -> min cost to get a string with i characters 
 // to get i characters, 
 // 1- we can add character to a string of (i-1) character so it is dp[i-1] + x 
 // 2- if i is even we can duplicate a string of i/2 character so it is dp[i/2] + y
 // 3- if i is odd so we can duplicate a string of ceil(i/2) to get i+1 character and then decrese one character so it is dp[(i+1)/2] + x + y 
 scanf("%d%d%d", &n, &x, &y);
 dp[0] = 0;
 for (int i = 1; i < N; i++)
 {
  dp[i] = min(dp[i-1] + x, 1LL * i * x); 
  if (i%2==0)
   dp[i] = min(dp[i], dp[i/2] + y); 
  else 
   dp[i] = min(dp[i], dp[(i+1)/2] + x + y); 
 }
 printf("%lld\n", dp[n]); 
}
