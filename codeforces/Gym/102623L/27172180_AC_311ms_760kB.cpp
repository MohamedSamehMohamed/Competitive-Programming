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
int a[10];
void soo()
{
  a[0]-=2;
  bool c = 0;
  for (int i = 9; i >= 0; i--)
  {
    while(a[i] > 0)
    {
      if(i)c=1;
      if(c)cout<<i;
      a[i]--;
    }
  }
  cout <<"0";
  if(c)cout <<"0";
  cout<<"\n";
}
void solve()
{
  for (int i = 0; i < 10; i++)cin >> a[i];
  if (a[0] > 1){
    soo();
    return;
  }
  vector<string> ans;
  if(a[0])ans.pb("0");
  if(a[4])ans.pb("4");
  if(a[8])ans.pb("8");
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
    {
      if (!i || !j)continue;
      int num = i + 10 * j;
      if (num % 4 || !a[i] || !a[j])continue;
      if (i == j && a[i] == 1)continue;
      a[i]--;a[j]--;
      string tm = "";
      for (int k = 9; k > 0; k--)
      {
        for (int c = 0; c < a[k]; c++)
          tm += char(k + '0');
      }
      tm += char(j + '0');
      tm += char(i + '0');
      ans.pb(tm);
      for (int c = 0; c < a[0]; c++)tm += "0";
      a[i]++;a[j]++;
    }
  for (int i = 1; i <= 9; i++)
  {
    int num = i * 10;
    if (a[i] && a[0] && num % 4 == 0)
    {
      a[i]--;a[0]--;
      string tm = "";
      for (int k = 9; k > 0; k--)
      {
        for (int c = 0; c < a[k]; c++)
          tm += char(k + '0');
      }
      tm += char(i + '0');
      tm += "0";
      for (int c = 0; c < a[0]; c++)tm += "0";
      ans.pb(tm);
      a[i]++;
      a[0]++;
    }
  }
  if (a[0] > 1 && a[1])
  {
    a[0]-=2;
    a[1]--;
    string tm = "";
    for (int k = 9; k > 0; k--)
    {
      for (int c = 0; c < a[k]; c++)
        tm += char(k + '0');
    }
    tm += "100";
    for (int c = 0; c < a[0]; c++)tm += "0";
    ans.pb(tm);
  }
  sort(rall(ans),[](string a, string b){
    if (SZ(a) == SZ(b)) return a < b;
    return SZ(a) < SZ(b);
  });
  if (SZ(ans) == 0)cout <<"-1\n";
  else
  {
    cout << ans[0] <<"\n";
  }

}
int main()
{
  int t;
  cin >> t;
  while(t--)solve();
}
