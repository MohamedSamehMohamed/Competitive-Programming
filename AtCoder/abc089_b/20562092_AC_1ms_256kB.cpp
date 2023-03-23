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
  int n ;
  cin >> n ;
  map <int ,int > mp;
  for (int i =0 ; i < n ;i++)
  {
    char x;
    cin >> x;
    mp[x]++;
  }
  if (SZ(mp) == 3)
  {
    cout <<"Three\n";
  }else
  cout <<"Four\n";
  //cerr << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
