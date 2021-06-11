// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      while(x % 2 == 0){
        mp[x]++;
        x/=2;
      }
    }
    cout << SZ(mp) <<"\n";
  }
 
}
