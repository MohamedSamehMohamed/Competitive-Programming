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
int n, s;
int main()
{
  cin >> n >> s;
  if (n == 1)
  {
    if (s == 1)
    {
      cout <<"NO\n";
    }else
    {
      cout <<"YES\n";
      cout << s <<"\n";
      cout << 1 <<"\n";
    }
    return 0;
  }
  ll cur = 1LL * (n-1) * 2;
  ll rm  = s - cur;
  if (rm <= 1 || ( (s-1)%2 == 0 && (s-1)/2 <= n-1 ))
  {
    cout << "NO\n";
    return 0;
  }
  cout <<"YES\n";
  for (int i = 1; i < n; i++)cout << "2 ";
  cout << rm <<"\n";
  cout << 1 <<"\n";
}
