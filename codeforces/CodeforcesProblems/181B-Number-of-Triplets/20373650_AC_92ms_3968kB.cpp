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
int cor[3000][2];
bool mp[2005][2005] ;
int main ()
{
  int n,ans=0;
  scanf ("%d" , &n );
  for (int i =0 ; i < n ;i++){
    scanf ("%d%d" , &cor[i][0] , &cor[i][1] ) ;
    cor[i][0] += 1000 ;
    cor[i][1] += 1000 ;
    mp[cor[i][0]][cor[i][1]]++;
  }
  for (int i =0 ; i < n ;i++)
  {
    for (int j =i+1 ; j < n ;j++)
    {
      if ((cor[i][0] +  cor[j][0] ) % 2   || (cor[i][1]  + cor[j][1] ) % 2  )continue ;
      int x = (cor[i][0] + cor[j][0])/2;
      int y = (cor[i][1] + cor[j][1])/2;
      if (mp[x][y])ans++;
      // WA on Test 8
    }
  }
printf ("%d\n" ,ans );
//cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
