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
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int e, o1, o2 ;
    e = o1 = o2 = -1;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      if (x & 1)
      {
        if (o1 == -1)o1 = i+1;
        else
        o2 = i+1 ;
      }else
      e = i+1;
    }
    if (~e || (~o1 && ~o2))
    {
      if (~e)
      {
        cout << 1 <<"\n";
        cout << e <<"\n";
      }else
      {
        cout << 2 <<"\n";
        cout << o1 <<" " << o2 <<"\n";
      }
    }else
    {
      cout <<"-1\n";
    }
  }
 
}
