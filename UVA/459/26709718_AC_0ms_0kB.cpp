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
const int N = 26;
int par[N];
int get_par(int u)
{
  return u == par[u] ? u: par[u] = get_par(par[u]);
}
void conect(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return ;
  par[u] = v;
}
int main()
{
  int t;
  cin >> t;
  char c;cin >> c;
  while(t--)
  {
    int n = c - 'A' + 1;
    for (int i = 0 ; i < n; i++)par[i] = i;
    string str;
    while(cin >> str)
    {
      if (SZ(str) == 1)
      {
        c = str[0];
        break;
      }
      conect(str[0]-'A', str[1]-'A');
    }
    set<int> st;
    for (int i = 0; i < n; i++)
      st.insert(get_par(i));
    cout << SZ(st) <<"\n";
    if (t)cout <<"\n"; 
  }
}