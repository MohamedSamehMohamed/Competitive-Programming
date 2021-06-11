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
string s, t;
set<int> st[26];
int n, m;
int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
  {
    for (int i = 0; i < 26; i++)st[i].clear();
    cin >> s >> t;
    n = SZ(s);
    m = SZ(t);
    for (int i = 0; i < n; i++)st[s[i]-'a'].insert(i);
    int idx = 0;
    int ans = 0;
    while(idx < m)
    {
      int curi = 0;
      int ss = 0;
      while(idx < m && st[ t[idx] - 'a' ].lower_bound(curi) != st[ t[idx] - 'a' ].end())
      {
        ss++;
        curi = *st[ t[idx] - 'a' ].lower_bound(curi);
        curi++;
        idx++;
      }
      if (!ss)break;
      ans++;
    }
    if (idx != m)ans = -1;
    printf("%d\n", ans);
 
  }
 
}
