#include<bits/stdc++.h>
using namespace std;
map<char, int> mp; 
int main()
{
 mp['*'] = mp['/'] = 2; 
 mp['+'] = mp['-'] = 1; 
 int t;cin >> t; 
 string str; 
 getline(cin, str);
 getline(cin, str); 
 string c = ""; 
 while(t--)
 {
  cout << c; 
  c = "\n"; 
  string x = "";
  while(getline(cin, str) && str.size())
   x += str; 
  stack<char> ops; 
  string ans = ""; 
  for (int i = 0, sz = x.size(); i < sz; i++)
  {
   if (x[i] >= '0' && x[i] <= '9')
    ans += x[i]; 
   else 
   {
    if (x[i] == '(')
     ops.push(x[i]); 
    else if (x[i] == ')')
    {
     while(ops.top() != '(')
      ans += ops.top(), ops.pop(); 
     ops.pop(); 
    }else 
    {
     while(!ops.empty() && mp[x[i]] <= mp[ops.top()])
      ans += ops.top(), ops.pop(); 
     ops.push(x[i]); 
    }
   }
  }
  while(!ops.empty())ans += ops.top(), ops.pop();
  cout << ans << "\n"; 
 }
}
