#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
string s;
int main()
{
  read_file();
  cin >> s; 
  int n = s.size();
  long long ans = 0;
  int frq[26]={0}; 
  frq[s[n-1]-'a']++;
  if (n-2 >= 0)
  frq[s[n-2] - 'a']++;
  for(int i = n-3; i >= 0; i--)
  {
    if (s[i] == s[i+1] && s[i+1] != s[i+2])
    {
      for(int j = 0; j < 26; j++)
        if (j != s[i]-'a')
        {
          ans += frq[j]; 
          frq[s[i]-'a'] += frq[j];
          frq[j] = 0;
        }
    }
    frq[s[i] -'a']++; 
  }
  cout << ans << "\n";
}
