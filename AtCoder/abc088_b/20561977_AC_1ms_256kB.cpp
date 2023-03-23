// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo (){fflush(stdout);}
using namespace std;
int a[100];
int n ;
int main ()
{
  cin >> n ;
  for (int i =0 ; i < n ;i++)cin >> a[i];
  sort(a,a+n);
  int ans =0 ;
  for (int i = n-1 , j =0  ;i >=0 ;i--,j=!j)
  {
    ans += ( j ? -a[i] : a[i]);
  }
  cout << ans <<"\n";
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
