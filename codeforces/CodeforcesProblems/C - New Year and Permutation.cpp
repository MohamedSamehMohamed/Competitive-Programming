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
const int N = 250009;
int n, m;
ll fact[N], ans;
int main()
{
 cin >> n >> m;
 fact[0] = 1;
 for (int i = 1; i < N; i++)fact[i] = (fact[i-1] * i)%m;
 for (int i = 1; i <= n; i++)
 {
  ll rep = n - i + 1;
  ans = (ans + rep * (fact[i] * fact[rep]%m))%m;
 }
 cout << ans << '\n';
}
