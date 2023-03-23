// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N], n, m; 
long long solve(int mx)
{
 long long need = 0;
 for (int i = 0; i < n; i++)
  need += (a[i] < mx? mx - a[i]: 0); 
 for (int i = 0; i < m; i++)
  need += (b[i] > mx? b[i] - mx: 0); 
 return need; 
}
int main()
{
 scanf("%d%d", &n, &m);
 for (int i = 0; i < n; i++) scanf("%d", a+i); 
 for (int i = 0; i < m; i++) scanf("%d", b+i); 
 int l = 1, r = 1e9;
 while(l < r)
 { 
  int m1 = l + (r-l)/3;
  int m2 = r - (r-l)/3; 
  if (solve(m1) > solve(m2))
   l = m1 + 1; 
  else 
   r = m2 - 1; 
 }
 printf("%lld\n", solve(l)); 
}
