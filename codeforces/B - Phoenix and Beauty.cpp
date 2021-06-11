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
const int N = 1000;
int a[N];
vector<int> ans;
set<int> st;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    st.clear();
    ans.clear(); 
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)st.insert(a[i]);
    if (SZ(st) > k)
    {
      cout <<"-1\n";
      continue;
    }
    int idx =0;
    for (int i : st)
    {
        if (idx < n && a[idx] == i)idx++; 
        ans.pb(i); 
    }
    while (SZ(ans) < k)ans.pb(1);
    for (int i = 0; idx < n; i++)
    {
        if (ans[i] == a[idx])idx++;
        ans.pb(ans[i]);
    }
    cout << SZ(ans) <<"\n";
    for (int i =0 ; i < SZ(ans); i++)
    {
        cout << ans[i] <<" ";
    }
    cout <<"\n"; 
    
  }
}
