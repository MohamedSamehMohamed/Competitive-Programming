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
      int a, b;
      cin >> a >> b;
      if (min(a, b) < 1)
      {
        cout << "0\n";
        continue;
      }
      cout << min({a, b, (a + b)/3}) <<"\n";
    }
 
}
