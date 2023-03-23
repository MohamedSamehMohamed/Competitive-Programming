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
  int n, m;
  cin >> n >> m;
  vector<int> num;
  set<string> st;
  string x;
  for (int i = 0; i < m; i++)
  {
    cin >> x;
    if (st.find(x) == st.end())
    {
      num.pb(SZ(x));
      st.insert(x);
    }
  }
  sort(all(num));
  int can = 0;
  int need =0 ;
  int sp = 0;
  for (int i = 0; i < SZ(num); i++)
  {
    if (need + sp + num[i] <= n)
    {
      can++;
      need += sp + num[i];
    }else break;
    sp = 1;
  }
  cout << can <<"\n";
}
