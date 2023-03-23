#include<bits/stdc++.h>
using namespace std;
string x, ans;
map<string, int> mp;
map<int, string> mp1;  
vector<int> nums;
int ret; 
void convertToRoamn()
{
 ans = "";
 int number = atoi(x.c_str());
 for (int i = 0; i < nums.size(); i++)
 {
  while(number >= nums[i])
  {
   ans += mp1[nums[i]]; 
   number -= nums[i]; 
  }
 }
} 
void convertToArabic()
{
 ret = 0;
 for (int i = 0, sz = x.size(); i < sz; i++)
 {
  string temp = x.substr(i, 1);
  int j = i+1;
  while(j < sz && mp[x.substr(j, 1)] > mp[x.substr(j-1, 1)])
  temp += x[j], j++; 
  i = j-1;   
  ret += mp[temp]; 
 }
}
int main()
{
 mp["I"] = 1; 
 mp["V"] = 5; 
 mp["X"] = 10; 
 mp["L"] = 50; 
 mp["C"] = 100; 
 mp["D"] = 500; 
 mp["M"] = 1000; 
 mp["IV"] = 4; 
 mp["IX"] = 9; 
 mp["XL"] = 40;
 mp["XC"] = 90; 
 mp["CD"] = 400; 
 mp["CM"] = 900; 
 for (auto i: mp)nums.push_back(i.second), mp1[i.second] = i.first; 
 sort(nums.rbegin(), nums.rend()); 
 while(cin >> x)
 {
  if (x[0] >= '0' && x[0] <= '9')
  {
   convertToRoamn(); 
   cout << ans << "\n"; 
  }
  else 
  {
   convertToArabic();
   cout << ret << "\n"; 
  }
 }
}
