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
bool pal (int x )
{
  int ar[10];
  int id =0 ;
  while (x)
  {
    ar[id++] = x%10;
    x/=10;
  }
  id--;
  for (int i= 0 ; i < id ;i++,id--)if (ar[i] != ar[id])return false ;
  return true ;
}
int main ()
{
  int a , b;
  cin >> a >> b ;
  int ans =0 ;
  while (a <= b )
  {
    ans += pal(a);
    a++;
  }
  cout << ans <<"\n";
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
