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
int a[1000];
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = n-1; i >= 0; i--)cout << a[i] <<" \n"[ i == 0];
  }
}
