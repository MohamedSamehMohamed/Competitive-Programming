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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
      ll a, b;
      cin >> a >> b;
      if (a > b)swap(a, b);
      ll ans =0 ;
      while(a != b)
      {
        if (a * 8 <= b)
        {
          a*=8;
        }else if (a * 4 <= b)
        {
          a *= 4;
        }else if (a * 2 <= b)
        {
          a *= 2;
        }else break;
        ans++; 
      }
      if (a != b)ans = -1;
      cout << ans <<"\n";
    }
}
