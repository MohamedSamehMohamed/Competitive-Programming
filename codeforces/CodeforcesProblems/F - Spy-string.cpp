// Author : Mohamed sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int n, m;
string x[10];
bool can(string cur)
{
 for (int i = 0; i < n; i++)
 {
  int er = 0;
  for (int j = 0; j < m; j++)er += (x[i][j] != cur[j]); 
  if (er > 1)return 0;
 }
 return 1;
}
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  cin >> n >> m;
  for (int i = 0; i < n; i++)cin >> x[i];
  string ans = "-1";
  for (int i = 0; i < m; i++)
  {
   string cur = x[0];
   bool done = 0;
   for (char c = 'a'; c <= 'z'; c++){
   cur[i] = c;
   if (can(cur))
   {
    done = 1;
    ans = cur;
    break;
   }
  }
  if (done)break;
  }
  cout << ans << "\n";
 }
}
