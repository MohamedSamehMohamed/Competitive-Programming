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
int a[N];
double EBS = 1e-6;
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    int n, L;
    cin >> n >> L;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    double l = 1, r = L, m;
    long double ans = 0;
    while(r - l > EBS)
    {
      m = (l+r)/2.0;
      ll curp = 0;
      ll sp = 1;
      long double L_time = 0, R_time = 0;
      for (int i = 0; i < n && a[i] <= m; i++)
      {
        L_time += (1.0*a[i] - curp)/sp;
        sp++;
        curp = a[i];
      }
      L_time += (1.0 * (m-curp))/sp;
      curp = L;
      sp = 1;
      for (int i = n-1; i >= 0 && a[i] >= m; i--)
      {
        R_time += (1.0*(curp-a[i]))/sp;
        sp++;
        curp = a[i];
      }
      R_time += (1.0*(curp-m))/sp;
      //cout << m <<" " << L_time <<" " << R_time <<"\n";
      if (fabs(L_time - R_time) <= EBS)
      {
        ans = L_time;
        break;
      }
      if (R_time > L_time)
      {
        l = m+0.00000001;
      }else
      {
        r = m-0.00000001;
      }
    }
    ans += EBS/2.0;
    cout << fixed;
    cout << setprecision(12) << ans <<"\n";
  }
}
