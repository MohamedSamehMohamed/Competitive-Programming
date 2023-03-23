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
ll a[100002];
ll pre[100002];
int n , m , k  ;
int L[100009];
int R[100009];
int D[100009];
int Tot[100009];
int main ()
{

  scanf ("%d%d%d" , &n , &m ,&k );
  for (int i =0 ; i < n ;i++)scanf ("%lld" ,a+i );
  for (int i =0 ; i < m ;i++)
  {
    int l , r , d ;
    scanf ("%d%d%d" , &l ,&r , &d );
    L[i] = l - 1;
    R[i] = r - 1 ;
    D[i] = d ;
  }
  for (int i =0 ; i < k ;i++)
  {
    int l , r;
    scanf ("%d%d" , &l ,&r );
    l--;
    r--;
    Tot[l]++;
    Tot[r+1]--;
  }
  for (int i =1 ; i < m ;i++)
  Tot[i] += Tot[i-1];
  for (int i =0 ; i < m ;i++)
  {
    pre[L[i]] += 1LL * Tot[i] * D[i] ;
    pre[R[i]+1] -= 1LL * Tot[i] * D[i] ;
  }

  for (int i = 1; i < n ;i++)
  {
    pre[i] += pre[i-1];
  }
  for (int i =0 ; i < n ;i++)
  {
    cout <<1LL *  a[i] + pre[i] <<" ";
  }


  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
