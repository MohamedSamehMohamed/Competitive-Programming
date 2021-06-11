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
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(all(v));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int cur = 1;
      int j = i;
      while (j < n && v[j] > cur)
      {
        cur++;
        j++;
      }
      if (j == n)break;
      ans++;
      i = j;
    }
    cout << ans <<"\n";
  }
}
