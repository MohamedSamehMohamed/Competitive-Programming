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
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;
int frq[26];
int main ()
{
string x ;
cin >> x ;
for (int i =0 ; i < SZ(x) ; i++)frq[x[i] - 'a']++;
for (int i =0 ; i < 25 ;i++)
{
  frq[i+1] += frq[i] / 2 ;
  frq[i] = frq[i] % 2 ;
}
for (int i = 25 ;i >= 0 ; i--)
{
  while (frq[i])
  {
    printf ("%c" , 97 + i );
    frq[i]--;
  }
}
cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
