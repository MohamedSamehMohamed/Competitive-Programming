// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
string x;
bool pal(int l, int r)
{
 if (l >= r)return 1;
 if (x[l] != x[r])return 0;
 return pal(l+1, r-1); 
}
int main()
{
 while(cin >> x)
 {
  set<string> ans;
  for (int i = 0; i < x.size(); i++)
   for (int j = i; j < x.size(); j++)
    {
     if (pal(i, j))
     ans.insert(x.substr(i, j-i+1)); 
    }
  printf("The string '%s' contains %d palindromes.\n", x.c_str(), (int)ans.size());
 }
}
