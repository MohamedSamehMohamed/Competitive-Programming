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
  FAST
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> ans;
    set<int> st;
    for (int i = 0; i < 2*n; i++)
    {
      int x;
      cin >> x;
      if (st.find(x) == st.end())
      {
        st.insert(x);
        ans.pb(x);
      }
    }
    for (int i = 0; i < n; i++)
      cout << ans[i] <<" ";
    cout <<"\n";
  }
}
