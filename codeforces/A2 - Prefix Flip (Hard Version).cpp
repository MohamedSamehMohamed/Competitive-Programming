// Author : Mohamed sameh
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
string x, y;
int n;
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  cin >> n >> x >> y;
  bool flip = 0;
  int l = 0, r = n-1;
  vector<int> ans;
  for (int i = n-1; i >= 0; i--)
  {
   if (flip)
   {
    if (x[r] != y[i])ans.pb(1);
   }else 
   {
    if (x[l] == y[i])ans.pb(1);
   }
   ans.pb(i+1);
   if (flip)
   r--;
   else 
   l++;
   flip^=1; 
  }
  cout << SZ(ans);
  for (int i : ans)cout << ' ' << i; 
  cout << '\n';
 }
}
