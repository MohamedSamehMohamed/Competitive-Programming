#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n, x; 
 cin >> n >> x;
 vector<int> v(n);
 for (int& i: v)cin >> i; 
 sort(v.begin(), v.end()); 
 int i = 0, j = n-1;
 int ans = 0; 
 while(i <= j)
 {
  j--; 
  if (v[j+1] + v[i] <= x)i++; 
  ans++; 
 }
 printf("%d\n", ans); 
}
