// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
string e;
int l, r; 
bool digit(char c)
{
 return c >= '0' && c <= '9'; 
}
bool check(char c)
{
 for (int i = 0, d = 0; i < e.size(); i++, d |= digit(e[i-1]))
  if (e[i] == c && d)
   return 1;  
 return 0; 
}
int nxt(int st)
{
 int number = 0, ne = 1;
 while(st < e.size() && e[st] == ' ')st++;
 if (e[st] == '-')ne = -1, st++;
 while(st < e.size() && digit(e[st]))
  number = number * 10 + (e[st]-'0'), st++; 
 r = st; 
 return ne * number; 
}
int prv(int st)
{
 while(st >= 0 && e[st] == ' ')st--; 
 while(st >= 0 && digit(e[st]))st--;
 if (e[st] == '-')st--; 
 l = st;
 st++;
 return nxt(st); 
}
int cal(int a, int b, char c)
{
 switch(c)
 {
  case '+':
   return a + b; 
  case '-':
   return a-b; 
  case '*':
   return a*b; 
  case '/': 
   return a/b; 
 }
 return -1; 
}
string getString(int number)
{
 if (number == 0)return "0";
 string pre = (number < 0? "-": ""); 
 number = abs(number); 
 string ret = ""; 
 while(number)
 {
  int d = number % 10;
  number /= 10;
  ret += d + '0'; 
 }
 reverse(ret.begin(), ret.end()); 
 return pre + ret;
}
void fix()
{
 string cur = "";
 int lst = 0, idx = -1; 
 for (int i = 0; i < e.size(); i++)
 {
  if (e[i] == '+')
  {
   if (lst != 0)continue; 
   cur += e[i];
   lst = 1; 
   idx = cur.size()-1; 
  }else if (e[i] == '-')
  {
   lst = -1;
   cur += e[i];
   idx = cur.size()-1;
   continue;
  }
  else 
  cur += e[i]; 
  if (digit(e[i]))lst = 0; 
 }
 e = cur; 
}
void solve(char c, char c1)
{
 for (int i = 0, d = 0; i < e.size(); i++, d |= digit(e[i-1]))
 {
  if ((e[i] == c || e[i] == c1) && d)
  {
   int a = prv(i-1);
   int b = nxt(i+1); 
   string pre = (l >= 0? e.substr(0, l+1): ""); 
   string suf = (r < e.size()? e.substr(r): "");
   string ret = getString(cal(a, b, e[i])); 
   e = pre + ret + suf;
   fix();   
   cout << e << "\n";
   return;
  }
 }
}
int main()
{
 while(getline(cin, e))
 {
  fix(); 
  cout << e << "\n"; 
  while(check('*') || check('/'))solve('*', '/'); 
  while(check('+') || check('-'))solve('+', '-');
  cout << "\n";
 }
}
