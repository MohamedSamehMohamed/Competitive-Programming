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
double cal()
{
  int x, y, z;
  cin >> x >> y >> z;
  return sqrt(x * x + y * y + z * z);
}
int main()
{
  int n;
  cin >> n;
  double ans = 1e9;
  while(n--)
  {
    ans = min(ans, cal());
  }
  printf("%.3f\n", ans);
}
