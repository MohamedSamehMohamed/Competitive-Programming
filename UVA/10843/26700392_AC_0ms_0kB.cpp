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
const int M = 2000000011;
int n;
ll mypow(int p)
{
  if (p <= 0)return 1;
  if (p == 1)return n;
  if (p&1)return (mypow(p-1) * n)%M;
  ll cur = mypow(p/2)%M;
  return (cur * cur)%M;
}
int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++)
  {
    scanf("%d", &n);
    printf("Case #%d: %lld\n", i, mypow(n-2));
  }
}
