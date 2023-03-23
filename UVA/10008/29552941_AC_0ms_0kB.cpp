// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
int frq[26]; 
string x;
int main()
{
 int n; 
 scanf("%d", &n);
 cin.ignore();
 while(n--)
 {
  getline(cin, x);
  for (int i = 0; i < x.size(); i++)
  {
   if (x[i] < 'a' && x[i] >= 'A' && x[i] <= 'Z') x[i] += 32; 
   if (x[i] >= 'a' && x[i] <= 'z')
    frq[x[i]-'a']++; 
  }
 }
 vector<pair<int, char>> v;
 for (int i = 0; i < 26; i++)
  if (frq[i])
   v.push_back({-frq[i], i+'A'}); 
 sort(v.begin(), v.end());
 for (int i = 0; i < v.size(); i++)
  printf("%c %d\n", v[i].second, -v[i].first);
}
