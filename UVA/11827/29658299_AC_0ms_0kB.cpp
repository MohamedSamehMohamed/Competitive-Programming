// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int a[101], n;
string str; 
void F()
{
 n = 0;
 stringstream in(str);
 int x;
 while(in >> x)a[n++] = x; 
}
void test()
{
 getline(cin, str); 
 F();
 // can be solved by factorize each number and count the frq of each one
 int mx = 0;
 for (int i = 0; i < n; i++)
  for (int j = i+1; j < n; j++)
   mx = max(mx, __gcd(a[i], a[j])); 
 cout << mx << "\n"; 
}
int main()
{
 int t; 
 cin >> t; 
 getline(cin, str);
 while(t--)
  test(); 
}
