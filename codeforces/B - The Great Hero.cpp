// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9; 
int a[N], b[N], n, A, B;
void test()
{
 scanf("%d%d%d", &A, &B, &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i); 
 for (int i = 0; i < n; i++)
  scanf("%d", b+i);
 vector<pair<long long, int>> v; 
 for (int i = 0; i < n; i++)
 {
  int cnt = (b[i]+A-1)/A;
  v.push_back({1LL*cnt * a[i], a[i]});
 }
 long long sum = 0;
 for (int i = 0; i < n; i++)sum += v[i].first;
 bool ok = 0;  
 for (int i = 0; i < n; i++)
 {
  long long cur = B - sum;
  if (cur >= 0)
  {
    ok = 1;break; 
  }
  if (-cur < v[i].second)
  {
   ok = 1;break; 
  }
 }
 if (ok)
  printf("YES\n"); 
 else 
  printf("NO\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
