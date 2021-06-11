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
const int N = 2e5 + 9;
int v[N]; 
int main()
{
  int t;
  scanf("%d", &t); 
  while (t--)
  {
    int n;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++)scanf("%d", v+i); 
    sort(v, v + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int cur = 1;
      int j = i;
      while (j < n && v[j] > cur)
      {
        cur++;
        j++;
      }
      if (j == n)break;
      ans++;
      i = j;
    }
    printf("%d\n", ans);
  }
}
