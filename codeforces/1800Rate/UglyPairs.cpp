#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int n;
char s[N];
int frq[26];
void print(string& str){
  for (int i = 0; i < str.size(); i++){
    int p = str[i] - 'a';
    while (frq[p]){
      frq[p]--;
      printf("%c", 'a' + p);
    }
  }
  printf("\n");
}
void test(){
  scanf(" %s", s);
  n = strlen(s);
  memset(frq, 0, sizeof frq);
  for (int i = 0; i < n; i++)
    frq[s[i] - 'a']++;
  string ans = "";
  string cur = "", left = "";
  for (int i = 0; i < 26; i++){
    if (frq[i] == 0) continue;
    int j = i + 1;
    cur += 'a' + i;
    while (j < 26 && frq[j]){
      cur += 'a' + j;
      j++;
    }
    i = j - 1;
    while (cur.size() >= 4){
      ans += cur[2];
      ans += cur[0];
      ans += cur[3];
      ans += cur[1];
      cur = cur.substr(4);
    }
    ans += left;
    if (cur.size() == 1){
      if (left.size() || ans.size() == 0){
        ans += cur;
        cur = "";
        left = "";
      }else {
        left += cur;
        cur = "";
      }
    }else if (cur.size() == 2){
      ans += cur[1];
      left = cur[0];
      cur = "";
    }else if (cur.size() == 3){
      ans += cur[2];
      ans += cur[0];
      left = cur[1];
      cur = "";
    }
  } 
  if (left.size()){
    int val = left[0] - 'a';
    bool ok = 0;
    for (int i = 0; i < ans.size(); i++){
      int nxt = ans[i] - 'a';
      int prv = (i-1 >= 0? ans[i-1] - 'a': 100);
      if (abs(val - nxt) != 1 && abs(val - prv) != 1){
        ans = ans.substr(0, i) + left[0] + ans.substr(i);
        ok = 1;
        break;
      }
    }
    if (!ok){
      printf("No answer\n");
      return;
    }
  }
  print(ans);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}

/*
a b c d
3 1 4 2 
c a d b  
*/