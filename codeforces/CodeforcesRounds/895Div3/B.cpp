// Author : Mohamed Sameh
// created in: 4:48 PM
#include <bits/stdc++.h>
using namespace std;
int n;
int d[102], s[102];
int room[355];
int ex[355];
void test(){
  scanf("%d", &n);
  memset(room, -1, sizeof room);
  for (int i = 0; i < n; i++){
    scanf("%d%d", d+i, s+i);
    if (room[d[i]] == -1)
      room[d[i]] = s[i];
    room[d[i]] = min(room[d[i]], s[i]);
  }
  int ans = 0;
  for (int i = 350; i >= 1; i--){
    int ti = i-1;
    for (int r = 1; r <= i; r++){
      ex[r] = 100000;
      if (room[r] == -1) continue;
        ex[r] = r-1+room[r];
    }
    bool ok = 1;
    for (int r = i; r >= 1; r--){
      if (ex[r] <= ti){
        ok = 0;
        break;
      }
      ti++;
    }
    if (ok){
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}