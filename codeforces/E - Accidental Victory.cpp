// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
int ans[N];  
void test()
{
 scanf("%d", &n);
 vector<pair<int,int>> v(n);
 long long sum = 0;
 for (int i = 0; i < n; i++)
 {
  ans[i] = 0; 
  scanf("%d", &v[i].first);
  v[i].second = i; 
  sum += v[i].first; 
 } 
 sort(v.begin(), v.end()); 
 ans[v[n-1].second] = 1;
 sum -= v[n-1].first;  
 int tot = 1;
 for (int i = n-2; i >= 0; i--)
 {
  if (sum >= v[i+1].first)
  {
  ans[v[i].second] = ans[v[i+1].second];
  if (ans[v[i].second])tot++; 
  }
  sum -= v[i].first; 
 }
 printf("%d\n", tot);
 for (int i = 0; i < n; i++)
 {
  if (ans[i])printf("%d ", i+1);
 }
 printf("\n"); 
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
