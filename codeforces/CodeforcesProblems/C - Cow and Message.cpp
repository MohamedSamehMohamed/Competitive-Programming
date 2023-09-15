// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
string x;
ll mx1[26], mx2[26][26];
int main()
{
  cin >> x;
  for (int i = 0; i < SZ(x); i++)
  {
    for (int j = 0; j < 26; j++)
      mx2[j][x[i]-'a']+=mx1[j];
    mx1[x[i]-'a']++;
  }
  ll ans = 0;
  for (int i = 0; i < 26; i++)
  {
    ans = max(ans, mx1[i]);
    for (int j = 0; j < 26; j++)
      ans = max(ans, mx2[i][j]);
  }
  cout << ans <<"\n";
}
