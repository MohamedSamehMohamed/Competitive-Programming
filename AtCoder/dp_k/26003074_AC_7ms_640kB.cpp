// Author : Mohamed Sameh
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
const int N = 1e2+1, M = 1e5+1;
int n, k, a[N], can[M];
int main()
{
  cin >> n >> k ;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i <= k; i++)
    for (int j = 0; j < n && !can[i] && a[j] <= i; j++)
      if (!can[i - a[j]])
        can[i] = 1;
  cout << (can[k] ? "First\n" : "Second\n");
}
