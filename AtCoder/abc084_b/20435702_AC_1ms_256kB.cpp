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
void F (){
ll a[100002];
ll pre[100002];
int n , m , k  ;
scanf ("%d%d%d" , &n , &m ,&k );
for (int i =0 ; i < n ;i++)scanf ("%lld" ,a+i );
for (int i =0 ; i < m ;i++)
{
  int l , r , d ;
  scanf ("%d%d%d" , &l ,&r , &d );
  l--;
  r--;
  pre[l]+=d;
  pre[r+1]-=d;
}
a[0] += pre[0];
for (int i =  1; i < n ;i++)
{
  pre[i] += pre[i-1];
  a[i] += pre[i];
}
for (int i =0 ; i < k ;i++)
{
  int l , r;
  scanf ("%d%d" , &l ,&r );
  l-=2;
  r--;

}
for (int i =0 ; i < n ;i++)
{
  cout << a[i] <<" ";
}
}
bool kk (int j , string x )
{
  for (int i =0 ; i < SZ(x) ;i++)
  {
    if (i == j )continue ;
    if (x[i] < '0' || x[i] > '9')return false;
  }
  return true ;
}
int main ()
{
  int a , b ;
  string x ;
  cin >> a >> b >> x ;
  if (x[a] == '-' && kk (a,x))
  {
    printf ("Yes\n");
  }else
  printf ("No\n");
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
