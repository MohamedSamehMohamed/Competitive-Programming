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
int n ;
int a[300];
bool v[300][300];
string s[300];
int dsu [300];
int find_set(int v) {
    if (v == dsu[v])
        return v;
    return find_set(dsu[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        dsu[b] = a;
}
int main ()
{
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++)dsu[i] = i ;
  for (int i =0 ; i < n ;i++)scanf ("%d" , a+i );
  for (int i =0 ; i < n ;i++)cin >> s[i];
  for (int i =0 ; i < n ;i++)for (int j =0  ; j < n ;j++)if (s[i][j] == '1') union_sets(i , j );
  for (int i =0 ; i + 1 < n ;i++)
  {
    for (int j =i+1 ; j < n ;j++)
    {
      if (a[i] < a[j] || find_set(i) != find_set(j))continue ;
      swap (a[i] , a[j]); 
    }
  }
  for (int i =0 ; i < n ;i++)printf ("%d " , a[i]);
  cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}