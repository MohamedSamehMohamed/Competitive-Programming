// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, a[N];
int ask(int x)
{
 cout << "? " << x << endl; 
 int res;cin >> res;
 return res; 
}
int main()
{
 memset(a, -1, sizeof a);
 cin >> n;
 int l = 1, r = n;
 while(l < r)
 {
  int m = (l+r)>>1;
  int v1 = ask(m);
  int v2 = ask(m+1); 
  if (v1 < v2)
   r = m; 
  else 
   l = m+1; 
 }
 cout << "! " << l << endl; 
}
