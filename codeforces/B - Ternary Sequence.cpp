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
  while(t--)
  {
    ll ans = 0;
    int a[3], b[3];
    for (int i = 0; i < 3; i++)cin >> a[i];
    for (int i = 0; i < 3; i++)cin >> b[i];
    int cur = min(a[2], b[1]);
    a[2]-=cur;
    b[1]-=cur;
    ans += cur * 2;
    cur = min(a[0], b[2]);
    a[0]-= cur;
    b[2]-= cur;
    cur = min(a[2], b[2]);
    a[2]-=cur;
    b[2]-=cur;
    cur = min(a[1], b[2]);
    a[1]-=cur;
    b[2]-=cur;
    ans -= 2 * cur;
    cout << ans << "\n";
  }
}
