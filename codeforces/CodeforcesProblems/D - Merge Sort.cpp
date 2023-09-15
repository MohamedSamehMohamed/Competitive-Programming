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
const int N = 1e5+9;
int n, k, a[N];
void solve(int l = 0, int r = n)
{
 if (k == 0)return;
 if (l + 1 >= r)return;
 int m = (l+r)>>1;
 k-=2;
 swap(a[m], a[m-1]);
 solve(l, m);
 solve(m, r);
}
int main()
{
 cin >> n >> k;
 k--;
 for (int i = 0; i < n; i++)a[i] = i+1;
 if (k % 2 == 0) solve();
 if (k == 0)
 {
  for (int i = 0; i < n; i++)cout << a[i] << " \n"[ i == n-1];
 }else 
  cout << "-1\n";
 
 
}
