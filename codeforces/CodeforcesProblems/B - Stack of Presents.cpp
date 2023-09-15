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
int n, m, a[N], b[N];
set<int> st;
int get_idx(int i, int val)
{
  while(i < n && a[i] != val){
    i++;
    st.insert(a[i-1]);
  }
  return i;
}
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    ll ans = 0 ;
    int idx = 0;
    while(idx < m && a[idx] == b[idx]){
      idx++;
      ans++;
    }
    if (idx == m)
    {
      cout << ans <<"\n";
      continue;
    }
    int i = idx;
    st.clear();
    int lst = 0;
    while(idx < m)
    {
      if (st.find(b[idx]) == st.end()){
      int cur = get_idx(i, b[idx]);
      int len = cur - i + lst;
      ans += 2 * len + 1;
      idx++;
      i = cur + 1;
    }else
    {
      st.erase(b[idx]);
      ans++;
      idx++;
    }
    lst = SZ(st);
    }
    cout << ans <<"\n";
  }
}
