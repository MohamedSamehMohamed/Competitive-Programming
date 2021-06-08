#include <bits/stdc++.h>
using namespace std;
const int N = 70;
const long long INF = 1e14; 
map<string, int> mp;
int a[N][3];  
double dp[N][N];
int n;  
long long P(int x)
{
 return 1LL * x * x; 
}
double dist(int i, int j)
{
 return sqrt(  P(a[i][0] - a[j][0])  + P(a[i][1] - a[j][1]) + P(a[i][2] - a[j][2]) );
}
int C; 
void test()
{
 cout << "Case " << ++C << ":\n"; 
 cin >> n; 
 for (int i = 0; i < N; i++)
  for (int j = 0; j < N; j++)
   dp[i][j] = INF; 
 mp.clear(); 
 for (int i = 0; i < n; i++)
 {
  string x;
  cin >> x >> a[i][0] >> a[i][1] >> a[i][2]; 
  mp[x] = i; 
 }
 int op;cin >> op;
 while(op--)
 {
  string x, y;cin >> x >> y;
  int u = mp[x];
  int v = mp[y];
  dp[u][v] = 0; 
 }
 for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
   dp[i][j] = min(dp[i][j], dist(i, j)); 
 for (int k = 0; k < n; k++)
  for (int i = 0; i < n; i++)
   for (int j = 0; j < n; j++)
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
 int q;
 cin >> q;
 while(q--)
 {
  string x, y;cin >> x >> y;
  int u = mp[x];
  int v = mp[y];
  cout <<"The distance from " << x << " to " << y << " is " << fixed << setprecision(0) << round(dp[u][v]) << " parsecs.\n"; 
 }
 
}
int main()
{
 int t; 
 cin >> t; 
 while(t--)
 {
  test();
 }
}
