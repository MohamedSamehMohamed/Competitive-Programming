#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 11092019;
int main()
{
 string x;
 cin >> x;
 ll ans = 1; 
 unordered_map<char,ll> mp;
 for(char c:x)
  mp[c]++;
 for(auto it:mp){
  ans *= (it.second + 1);
  ans %= mod;
 }
 
 cout<<ans<<endl;
}
