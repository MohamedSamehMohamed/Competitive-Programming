#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int N = 1e6 + 9;
int n;
int a[N];
void test()
{
  scanf("%d", &n);
  vector<long long> v(n);
  for(int i = 0; i < n; i++)
    scanf("%lld", &v[i]); 
  while(v.size() != 1)
  {
    int idx = 0;
    long long bst = 1e18;
    for(int i = 0; i < n; i++)
    {
      int nx = (i + 1) % n;
      if (v[i] - v[nx] < bst)
        idx = i, bst = v[i] - v[nx]; 
    }
    cout << v[idx] <<" " << v[(idx+1)%n] <<"\n";
    v[idx] -= v[(idx+1)%n];
    idx = (idx + 1) % n; 
    v.erase(v.begin() + idx); 
    n--;
  }
  cout << v[0] << "\n";
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
