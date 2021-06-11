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
const int N = 2e5+9;
int a[N], n;
ll ans[N];
int main()
{
 cin >> n;
 for (int i = 0; i < n; i++)cin >> a[i];
 for (int j = 0; j < 20; j++)
 {
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
   if (a[i] & (1<<j))cnt++;
  }
  for (int i = 0; i < cnt; i++)ans[i]|=(1<<j);
 }
 ll sum = 0;
 for (int i = 0; i < n; i++)sum += ans[i] * ans[i];
 cout << sum << '\n';
}
