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
int n , m ;
int a[100000];
int b[100000];
int main ()
{
  scanf ("%d%d" , &n ,&m );
  int ans = n ;
  for (int i =0 ; i < m ;i++)scanf ("%d%d" ,a+i , b+i ) , ans = min (ans , b[i] - a[i] + 1);
  cout << ans <<"\n";
  for (int i =0; i < n ;i++)
  {
    // Wrong Ans
    cout << i % ans <<" ";
  }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
