// Author : Mohamed Sameh
// created in: 4:47 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
char a[N];
int n, K;
int frq[2][26];
void rev(int j, int k){
  int tk0 = (K+1)/2, tk1 = K/2;
  vector<int> nfrq(26, 0);
  vector<int> nfrq2(26, 0);
  for (int jj = j, kk = k; tk0 + tk1 > 0 && jj < 26 && kk < 26;jj++,kk++){
    while (tk0 > 0 && frq[0][jj] == 0)jj++;
    while (tk1 > 0 && frq[1][kk] == 0)kk++;
    if (tk0 > 0){
      if (tk0 >= frq[0][jj]){
        nfrq[jj] += frq[0][jj];
        tk0 -= frq[0][jj];
        frq[0][jj]=0;
      }else {
        nfrq[jj] += tk0;
        frq[0][jj] -= tk0;
        tk0 = 0;
      }
    }
    if (tk1 > 0){
      if (tk1 >= frq[1][kk]){
        nfrq2[kk] += frq[1][kk];
        tk1 -= frq[1][kk];
        frq[1][kk]=0;
      }else {
        nfrq2[kk] += tk1;
        frq[1][kk] -= tk1;
        tk1 = 0;
      }
    }
  };
  for (int rep = 0; rep < 26; rep++){
    frq[0][rep] += nfrq2[rep];
    frq[1][rep] += nfrq[rep];
  }
}
void test(){
  scanf("%d%d %s", &n, &K, a);
  memset(frq, 0, sizeof frq);
  int even = 0, odd = 0;
  for (int i = 0; i < n; i+=2)
  {
    frq[i%2][a[i] - 'a']++;
    even++;
    if (i + 1 < n)
    {
      odd++;
      frq[(i+1) % 2][a[i+1]-'a']++;
    }
  }
  int i = 0;
  int turn = 0;
  while (i < n && even > 0 && odd > 0){
    int j = 25, k = 25;
    for (int c = 0; c < 26; c++){
      if (frq[0][c]){
        j = min(j, c);
      }
      if (frq[1][c]){
        k = min(k, c);
      }
    }

    bool canDoK = 0;
    canDoK = K % 2 == 0;
    if (turn == 0){
      if (j <= k || !canDoK){
        a[i++] = j + 'a';
        frq[0][j]--;
        even--;
      }else {
        //rev(j, k);
        swap(frq[0], frq[1]);
        a[i++] = k + 'a';
        frq[0][k]--;
        even--;
      }
    }else {
      if (k <= j || !canDoK){
        a[i++] = k + 'a';
        frq[1][k]--;
        odd--;
      }else {
        //rev(j, k);
        swap(frq[0], frq[1]);
        a[i++] = j + 'a';
        frq[1][j]--;
        odd--;
      }
    }
    turn ^= 1;
  }
  while (i < n){
    for (int j = 0; j < 26; j++){
      for (int k = 0; k < 2; k++)
        while (frq[k][j] && i < n){
          frq[k][j]--;
          a[i++] = j + 'a';
        }
    }
  }
  printf("%s\n", a);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
 * panda
 * panda
 * a n p
 * a d
 * aa ndp
 * aa pdn
 * aandp
 *
 * abcde
 * a c e
 * b d
 *
 * edcba
 * e c a
 *
 */