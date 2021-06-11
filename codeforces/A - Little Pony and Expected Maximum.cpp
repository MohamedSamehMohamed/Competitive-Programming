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
const int N = 1e5+9;
int n, m;
double mypow(double b, int p)
{
  if (p == 0)return 1;
  if (p & 1)return b * mypow(b, p-1);
  double cur = mypow(b, p/2);
  return cur * cur;
}
int main()
{
  scanf("%d%d", &m, &n);
  double ans = m;
  for (int i = 1; i < m; i++)
  ans -= mypow(1.0 * i / m, n);
  printf("%.9f\n", ans);
 
}
