// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf("%d" , &n )
void fo (){fflush(stdout);}
using namespace std;
ll fact (int x ){return (x <= 1 ? 1 : 1LL * x * fact (x-1));}
int main ()
{
  int n , m  ;
  cin >> n >> m ;
  for (int i =0  ;i <= n ; i++)
  {
    for (int j =0 ; j <= n ;j++)
    {
      if (n - i - j < 0 )continue ;
      // cast not ness 
      ll cur = 1LL * 10000 * i + 1LL * 5000 * j + 1LL * (n - i - j) * 1000;
      if (cur == m )
      {
        cout << i <<" " << j <<" " << n-i-j <<"\n";
        return 0;
      }
    }
  }
  cout <<"-1 -1 -1\n";
//cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
