// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 2e5+9;
int n, a[N], lower[N], upper[N], dp[N];
int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    lower[i] = -1;
    upper[i] = n;
    cin >> a[i];
  }
  stack<int> stk;
  stk.push(0);
  for(int i = 1; i < n; i++)
  {
    while(!stk.empty() && a[i] < a[stk.top()])
    {
      upper[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  stk = stack<int>();
  stk.push(n-1);
  for(int i = n-2; i >= 0; i--)
  {
    while(!stk.empty() && a[i] < a[stk.top()])
    {
      lower[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  for (int i = 0; i < n; i++)
  {
    int sz = upper[i] - lower[i] - 1;
    dp[sz] = max(dp[sz], a[i]);
  }
  for (int i = n-1; i >= 0; i--)dp[i] = max(dp[i], dp[i+1]);
  for (int i = 1; i <= n; i++)
  {
    cout << dp[i] << ' ';
  }
}
