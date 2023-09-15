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
const int N = 1e5+1;
int a[N], b[N], n;
int main()
{
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i], b[i]=0;
    b[0] = a[0];
    for (int i = 0; i < n; i++)
    {
      if (a[i] == n)
      {
        b[i] = n;
        break;
      }
    }
    set<int> st;
    for (int i = 1; i < n; i++)
    {
      if (b[i])continue;
      if (a[i] != a[i-1])b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
      if (b[i])st.insert(b[i]);
    }
    vector<int> vt;
    for (int i = 1; i <= n; i++)
    {
      if (st.find(i) == st.end())vt.pb(i);
    }
    int j =0;
    for (int i = 0; i < n && j < SZ(vt); i++)
    {
      if (b[i])continue;
      b[i] = vt[j];
      j++;
    }
    st.clear();
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
      if (b[i] == 0)ok = 0;
      st.insert(b[i]);
    }
    int mx = b[0];
    for (int i = 1; i < n; i++)
    {
      mx = max(mx, b[i]);
      if (a[i] != mx)
      {
        ok = 0;
        break;
      }
    }
    if (ok && SZ(st) == n)
    {
      for (int i = 0; i < n; i++)
        cout << b[i] <<" ";
      cout <<"\n";
    }else
    {
      cout <<"-1\n";
    }
  }
}
