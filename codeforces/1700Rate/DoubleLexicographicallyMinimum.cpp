#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
char s[N];
int n;
int frq[26];
void test(){
  scanf(" %s", s);
  n = strlen(s);
  memset(frq, 0, sizeof frq);
  for (int i = 0; i < n; i++)
    frq[s[i] - 'a']++;
  int l = 0, r = n-1;
  
  for (int i = 0; i < 26; i++){
    while (frq[i] > 1){
      frq[i] -= 2;
      s[l++] = s[r--] = char('a' + i);
    }
    if (frq[i] && l == r){
        s[l] = char('a' + i);
        break;
    }
    if (frq[i]){
        frq[i]--;
        int nxt = i + 1;
        while (frq[nxt] == 0)
            nxt++;
        if (frq[nxt] == r - l){
            while (frq[nxt] > 1){
                s[l++] = s[r--] = char('a' + nxt);
                frq[nxt] -= 2;
            }
            if (frq[nxt])
            {
                s[l++] = char('a' + nxt);
                frq[nxt]--;
            }
            s[r--] = char('a' + i);
        }else {
            for (nxt = 0; nxt < 26; nxt++){
                while (frq[nxt]){
                    frq[nxt]--;
                    s[l++] = char('a' + nxt);
                }
            }
            s[r--] = char('a' + i);
        }
    }
  }
  printf("%s\n", s);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}
