// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
char x[N];
int n, val[26];
long long ans;
int main()
{
  for (int i = 0; i < 26; i++)
   scanf("%d", val+i);
  
  scanf(" %s", x);
  n = strlen(x);
  long long pre = 0; 
  map<pair<long long, char>, int> mp; 
  for (int i = 1; i <= n; i++)
  {
   ans += mp[{pre,x[i-1]}];
   pre += val[x[i-1]-'a']; 
   mp[{pre, x[i-1]}]++; 
  } 
  
  printf("%lld\n", ans);
}
