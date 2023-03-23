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
int pre[101];
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m ;
    while (m--)
    {
      int l, r ;
      cin >> l >> r;
      l--;
      pre[l]++;
      pre[r]--;
    }
    for (int i =1; i < n ;i++)pre[i]+=pre[i-1];
    for (int i =0; i < n ;i++)
    {
      if (pre[i] != 1 )
      {
        cout << i+1 <<" " << pre[i] <<"\n";
        return 0;
      }
    }
    cout <<"OK\n"; 
}
