// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int a[N], ans[N]; 
void build(int l = 0, int r = n-1, int dep = 0)
{
 if (l > r)return; 
 if (l == r)
 {
  ans[l] = dep;
  return; 
 }
 int idx = l;
 for (int i = l; i <= r; i++)
  if (a[i] > a[idx])idx = i;
 ans[idx] = dep; 
 build(l, idx-1, dep + 1);
 build(idx+1, r, dep + 1); 
 
}
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", a+i); 
 build();
 for (int i = 0; i < n; i++)
  printf("%d%c", ans[i], (i+1==n? '\n': ' ')); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
