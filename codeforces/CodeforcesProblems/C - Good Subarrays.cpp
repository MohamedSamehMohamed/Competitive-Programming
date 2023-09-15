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
const int N = 1e5+ 9;
int n, t, pre[N];
ll ans;
string x;
int main()
{
  cin >> t;
  while(t--)
  {
    ans = 0;
    cin >> n >> x;
    map<int,int> mp;
    mp[0]=1;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
      cur += x[i] - '0';
      ans += mp[cur - i - 1]++;
    }
    cout << ans <<"\n";
  }
}
