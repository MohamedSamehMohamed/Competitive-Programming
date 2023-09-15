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
string ans = "", x;
int bad;
void solve()
{
  if (cin >> x)
  {
    ans += x;
    if (x == "pair")
    {
      ans += "<";
      solve();
      ans += ",";
      solve();
      ans+=">";
    }
  }else bad = 1;
}
int main()
{
  int n;cin >> n;
  solve();
  if (bad || (cin >> x))
  {
    cout <<"Error occurred\n";
  }else
  {
    cout << ans << '\n';
  }
}
