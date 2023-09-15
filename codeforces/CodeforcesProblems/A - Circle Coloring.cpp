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
const int N = 200;
int n, a[3][N];
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int j = 0; j < 3; j++)
      for (int i = 0; i < n; i++)
        cin >> a[j][i];
    int cur = a[0][0];
    int fi  = cur;
    cout << cur <<" ";
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < 3; j++)
        if (a[j][i] != cur && a[j][i] != fi)
        {
          cur = a[j][i];break;
        }
        cout << cur <<" ";
    }
    cout <<"\n";
  }
}
