#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
int main()
{
  read_file();
  int n;cin >> n;
  int ans = 0; 
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
      if (1LL * i * j > n)break; 
      for(int k = 1; k <= n; k++)
      {
        if (1LL * i * j * k > n)
          break; 
        ans++;
      }
    }
    cout << ans <<"\n";
}
