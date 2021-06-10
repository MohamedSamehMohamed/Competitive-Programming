#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5 + 9; 
int a[N]; 
int dp[N]; 
int lst[N]; 
string x;
int n;
int mx = -1e9;
int st, en;    
void solve(int c)
{
 for (int i = 0; i < n; i++)
 {
  a[i] = (x[i] == 'B'? c: -c); 
 }
 dp[0] = a[0]; 
 lst[0] = 0; 
 for (int i = 1; i < n; i++)
 {
  int s1 = dp[i-1] + a[i]; 
  int s2 = a[i]; 
  dp[i] = max(s1, s2); 
  if (s1 >= s2)
  {
   lst[i] = lst[i-1]; 
  }else 
  {
   lst[i] = i; 
  }
 }
 /*
 BBRRBRRBRB
 BBRBBRRB
 */
 for (int i = 0; i < n; i++)
 {
  int nst = lst[i]; 
  int nen = i; 
  if (dp[i] > mx)
  {
   mx = dp[i];
   st = nst; 
   en = nen;   
  }else if (dp[i] == mx)
  {
   if (nst < st || (nst == st && nen < en))
   {
    st = nst; 
    en = nen; 
   }
  }
 }
}
int main(){
 cin >> x; 
 n = x.size(); 
 solve(1); 
 solve(-1); 
 cout << st + 1 << ' ' << en + 1 << '\n';
 
}
