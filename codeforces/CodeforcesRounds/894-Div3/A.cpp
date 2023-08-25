// Author : Mohamed Sameh
// created in: 4:31 PM
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[20];
void test(){
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  string tar = "vika";
  int j = 0;
  for (int i = 0; i < m; i++){
    bool found = 0;
    for (int k = 0; k < n; k++){
      if (s[k][i] == tar[j]){
        found = 1;
        break;
      }
    }
    if (found) j++;
    if (j == 4) break;
  }
  if (j == 4){
    cout <<"YES\n";
  }else
    cout <<"NO\n";
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}