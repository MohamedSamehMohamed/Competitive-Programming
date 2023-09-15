#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a, b, ans = 0;
  cin >> a >> b;
  while(min(a, b) > 0)
  {
   if (a > b)swap(a, b);
   ans += b/a;
   b %= a; 
   
  }
  cout << ans << '\n'; 
}
