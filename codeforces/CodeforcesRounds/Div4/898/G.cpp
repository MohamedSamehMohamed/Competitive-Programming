// Author : Mohamed Sameh
// created in: 5:06 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char s[N];
int n;
vector<int> v;
int dp[N], vis[N], vid;
int solve(int index=0){
  if (index == n)
    return 0;
  int& ret = dp[index];
  if (vis[index] == vid) return ret;
  vis[index] = vid;
  ret = solve(index+1);
  if (index + 1 == n) return ret;
  // AB
  bool moreThanOne = abs(v[index+1]) > 1;
  if (v[index] < 0){
    // AAAB
    // AABC
    // ABCC
    if (moreThanOne){
      ret = max(ret, -v[index] + solve(index+1));
    }else
      ret = max(ret, -v[index] + solve(index+2));
  }else {
    // BA
    // BBBAAA
    // BBCBAA
    // BBCCBA
    // BBBBCB
    ret = max(ret, -v[index+1] + solve(index+2));
  }
  return ret;
}
void test(){
  vid++;
  scanf(" %s", s);
  n = strlen(s);
  v.clear();
  for (int i = 0; i < n; i++){
    int j = i + 1;
    while (j < n && s[j] == s[i])
      j++;
    v.push_back(j - i);
    if (s[i] == 'A')
      v.back() *= -1;
    i = j - 1;
  }
  n = v.size();
  int ans = solve();
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
 * BBBBBA
 * BBBBCB
 * AAAAAAAB
 * AAAAAABC
 * AAAAABCC
 * AAAABCCC
 * AAABCCCC
 * AABCCCCC
 * ABCCCCCC
 * BCCCCCCC
 *
 * BBBBBBBBA
 * ABA
 */