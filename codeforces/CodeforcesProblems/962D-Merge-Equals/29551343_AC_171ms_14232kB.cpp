// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 15e4 + 9;
long long a[N]; 
int n, rm; 
map<long long, set<int>> frq; 
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  scanf("%lld", a+i);
  frq[a[i]].insert(i); 
 }
 for (auto &i: frq)
 {
  while (i.second.size() > 1)
  {
   int x = *i.second.begin(); i.second.erase(i.second.begin());
   int y = *i.second.begin(); i.second.erase(i.second.begin());
   a[x] = -1;rm++; 
   a[y] = i.first * 2;
   frq[i.first*2].insert(y);  
  }
 }
 printf("%d\n", n-rm);
 for (int i = 0; i < n; i++)
 {
  if (~a[i])
   printf("%lld ", a[i]); 
 }
 printf("\n"); 
 
 
}
