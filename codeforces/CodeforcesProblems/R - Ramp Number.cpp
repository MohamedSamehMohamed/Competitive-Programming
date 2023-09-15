#include <bits/stdc++.h>
 
using namespace std;
const int N = 90;
long long dp[N][12][2];
string x;
int n;  
bool good()
{
 for (int i = 1; i < n; i++)
  if (x[i] < x[i-1])
   return 0; 
 return 1; 
}
long long solve(int idx = 0, int lst = 0, bool f1 = 0)
{
 if (idx == n)
  return 1; 
 long long &ret = dp[idx][lst][f1]; 
 if (~ret)return ret; 
 ret = 0;
 int mn = lst; 
 int mx = (f1? 9: x[idx] - '0'); 
 for (int i = mn; i <= mx; i++)
 {
  ret = ret + solve(idx + 1, i, (f1 | (i < mx)) ); 
 }
 return ret; 
}
void test()
{
 cin >> x;
 memset(dp, -1, sizeof dp);
 n = x.size(); 
 if (!good())
  cout << "-1\n"; 
 else 
  cout << solve()-1 << '\n';
}
int main()
{
 int t; 
 cin >> t;
 while(t--)
 {
  test();
 }
}
