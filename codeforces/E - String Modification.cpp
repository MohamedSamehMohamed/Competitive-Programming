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
const int N = 5e3+1000;
int n;
int a[N];
string x;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> x;
    int best = 1;
    string ans = x, tm;
    tm = x;
    for (int k =2; k <= n; k++)
    {
      int num = n - k + 1;
      tm = "";
      for (int i = k-1; i < n; i++)tm += x[i];
      if (num&1)
      for (int i = k-2; i >= 0; i--)tm += x[i];
      else
      for (int i = 0; i < k-1; i++)tm += x[i];
      if (tm < ans)
      {
        ans = tm;
        best = k;
      }
    }
    cout << ans <<"\n" << best <<"\n";
  }
 
}
