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
int a[N], vis[N];
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> vis[i];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])v.pb(a[i]);
    }
    sort(rall(v));
    int j = 0;
    for (int i = 0;j < SZ(v) && i < n; i++)
    {
      if (!vis[i])
      {
        a[i] = v[j];
        j++;
      }
    }
    for(int i = 0; i < n; i++)cout << a[i] <<" \n"[ i + 1 == n];
  }
}
