#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5 + 9; 
int a[N]; 
int main()
{
 freopen("looking.in", "r", stdin);
 int t; 
 scanf("%d", &t);
 while(t--){
 int n, k;
 scanf("%d%d", &n, &k);
 for (int i = 0; i < n; i++)
 {
  scanf("%d", a+i); 
 }
 sort(a, a+n);
 long long ans =0;
 for (int i = n-1; k && i >= 0; i--)
 {
  long long cur = (ans | a[i]);
  if (cur != ans)
  {
   ans = cur; 
   k--; 
  }
 }
 printf("%lld\n", ans);
 }
}
