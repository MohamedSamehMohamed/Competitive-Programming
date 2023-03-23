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

int a[100000];
map <int ,int > di ;
int main ()
{
  int n , m ;
  scanf ("%d%d" , &n ,&m );
  int dif = 0;
  for (int i =0 ; i < n ;i++){
    scanf ("%d" ,a+i ) ;
    if (++di[a[i] % m] == 1 )dif++;
  }
  int ans =0 ;
  for (int i =0 ; i < n ;i++)
  {
    int cur ;
    scanf ("%d" ,&cur );cur--;
    if (dif == 1 )break;
    ans++;
    if (--di[a[cur]%m] == 0 )dif--;
  }
  printf ("%d\n" , min (n-1 , ans ));
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
