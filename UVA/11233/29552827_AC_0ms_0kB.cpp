// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int n, m; 
char x[25], y[25];
string vowl = "aeiou";
bool constant(char x)
{
 for (int i = 0; i < vowl.size(); i++)
  if (x == vowl[i])
   return 0;
 return 1; 
} 
int main()
{
 scanf("%d%d", &n, &m);
 map<string, string> mp;
 for (int i = 0; i < n; i++)
 {
  scanf(" %s %s", x, y);
  string a = x;
  string b = y;
  mp[a] = b; 
 }
 for (int i = 0; i < m; i++)
 {
  scanf(" %s", x);
  string a = x; 
  if (mp.find(x) != mp.end())
   printf("%s\n", mp[a].c_str()); 
  else 
  {
   if (a.back() == 'x' || a.back() == 's' || a.back() == 'o')
   {
    a += "es"; 
   }else 
   {
    if (a.size() == 1)
    {
     a += "s";
    }else 
    {
     string b = a.substr(a.size()-2); 
     if (b == "ch" || b == "sh")
     {
      a += "es"; 
     }else 
     {
      if (a.back() == 'y' && constant(a[a.size()-2]))
      {
       a.pop_back();
       a += "ies"; 
      }else 
      a += "s"; 
     }
    }
   }
   printf("%s\n", a.c_str()); 
  }
 }
}
