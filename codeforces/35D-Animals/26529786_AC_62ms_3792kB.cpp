// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int main()
{
  freopen("input.txt" , "r" , stdin );
  freopen("output.txt" , "w" , stdout);
  int n, x;
  cin >> n >> x ;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    v.pb(val * (n-i));
  }
  sort(all(v));
  int c =0;
  for (int i = 0; i < n ; i++)
  {
    if (x - v[i] < 0 )break;
    x-=v[i];
    c++;
  }
  cout << c <<"\n";
}
