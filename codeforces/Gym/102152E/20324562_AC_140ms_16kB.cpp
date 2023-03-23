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
string a , b , c ;
int frq[26];
int main ()
{
  int t ;
  scanf ("%d" ,&t );
  while (t--)
  {
    memset (frq, -1 ,sizeof frq );
    int n , m ;
    scanf ("%d%d" , &n ,&m );
    cin >> a >> b >> c ;
    bool done = 1;
    for (int i = 0 ; i < n ;i++)
    {
      if (frq[a[i] - 'a'] == -1 )
      frq[a[i]-'a'] = b[i] - '0';

      frq[a[i]-'a'] = min (frq[a[i] - 'a'] , b[i] - '0');
    }
    int ans =0 ;
    for (int i =0 ; i < m ;i++)
    {
      if (frq[c[i]-'a'] == -1 )done = 0;
      ans += frq[c[i]-'a'];}
      if (done)
    printf ("%d\n" ,ans );
    else
    printf ("-1\n"); 
  }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
