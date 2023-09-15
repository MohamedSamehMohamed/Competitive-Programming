#include <bits/stdc++.h>
 
using namespace std;
 
#define SZ(v) (int)v.size()
 
 
int T;
string str;
void valid(string s,string &a,string &b,string &c,string &op){
 
 while(SZ(s) && s.back() != '='){
  c += s.back();
  s.pop_back();
 }
 s.pop_back();
 while(SZ(s) && ((s.back() <= '9' && s.back() >= '0') || s.back() == '?')){
  b += s.back();
  s.pop_back();
 }
 
 if(SZ(s)>2 && ((s[SZ(s)-2] > '9' || s[SZ(s)-2] < '0') && s[SZ(s)-2] != '?')){
  b += s.back();
  s.pop_back();
 }
 
 op += s.back();
 s.pop_back();
 a = s;
 
 
 reverse(c.begin(),c.end());
 reverse(b.begin(),b.end());
 
}
 
int valid(string s,char v){
 for(char &c:s){
  if(c == '?')
   c = v;
 }
 bool flage = (s[0] < '0' || s[0] > '9') && s[0] != '?';
 int idx = flage;
 int su = 0;
 for(int i=idx;i<SZ(s);++i){
  su*=10;
  su += (s[i] - '0');
 }
 if(flage)
  su *= -1;
 return su;
}
 
bool cal(string s){
 if (SZ(s) == 1)return 0; 
 return s[0] == '?' || (SZ(s) >= 2 && s[0] == '-' && s[1] == '?');
}
map<char,bool> mp;
int Solve(string l,string r,string s,string op){
 long long a,b,c;
 for(char i='0';i<='9';++i){
  if(i == '0' && (cal(l) || cal(r) || cal(s)))
   continue;
  if(mp.count(i))
   continue;
  if(op[0] == '+'){
   a = valid(l,i);
   b = valid(r,i);
   c = valid(s,i);
   if(a+b == c)
    return i-'0';
  }else if(op[0] == '-'){
   a = valid(l,i);
   b = valid(r,i);
   c = valid(s,i);
   if(a-b == c)
    return i-'0';
  }else{
   a = valid(l,i);
   b = valid(r,i);
   c = valid(s,i);
   if(a*b == c)
    return i-'0';
  }
 // cout<<a<<" "<<b<<" "<<c<<"\n";
 }
 //cout<<"\n\n";
 return -1;
}
 
 
int main()
{
 ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
 int t; 
 cin>>T;
 while(T--){
  cin>>str;
  mp.clear();
  for(char i:str){
   if(i >= '0' && i <= '9')
    mp[i] = true;
  }
  string a,b,c,op;
  valid(str,a,b,c,op);
  cout<<Solve(a,b,c,op)<<endl;
  
 }
 
}
