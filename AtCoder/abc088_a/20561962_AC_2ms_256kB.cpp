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

int main ()
{
  int n , m ;
  cin >> n >> m ;
  n%=500 ;
  if (n <= m )
  {
    cout <<"Yes\n";
  }else
  cout <<"No\n"; 
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
