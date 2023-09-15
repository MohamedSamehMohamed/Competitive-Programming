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
ll a[3];
int main()
{
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  cout << min(a[0] + a[1], (a[0]+a[1]+a[2])/3) << '\n';
}
