#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e5 + 9;
int n, m;
bool seen[N];
int main()
{
  read_file();
  scanf("%d%d", &n, &m);
  set<int> uni; 
  for(int i = 0; i < n; i++)
  {
    int x;scanf("%d", &x);
    for(int j = 2; j <= x/j; j++)
    {
      if (x % j == 0)
      {
        uni.insert(j);
        while(x % j == 0)
          x /= j; 
      }
    }
    if (x != 1)
      uni.insert(x); 
  }
  for(int i: uni)
  {
    for(int j = i; j < N; j+=i)
      seen[j] = 1;
  }
  vector<int> ans;
  for(int i = 1; i <= m; i++)
    if (!seen[i])
      ans.push_back(i);
  printf("%d\n", (int)ans.size());
  for(int i: ans)printf("%d\n", i);

  
}
