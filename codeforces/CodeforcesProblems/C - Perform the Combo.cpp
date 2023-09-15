// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
int n, m;
int pre[N];
string x;
int frq[26];
void solve()
{
  cin >> n >> m >> x;
  memset(frq, 0, sizeof frq);
  for (int i = 0; i <= n; i++)pre[i] = 0;
  for (int i = 0; i < m; i++)
  {
    int x;cin>>x;
    pre[0]++;
    pre[x]--;
  }
  for (int i = 1; i < n; i++)pre[i] += pre[i-1];
  for (int i = 0; i < n; i++)
  {
    pre[i]++;
    frq[x[i]-'a'] += pre[i];
  }
  for (int i = 0; i < 26; i++)
    cout << frq[i] <<" \n"[ i == 25];
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
