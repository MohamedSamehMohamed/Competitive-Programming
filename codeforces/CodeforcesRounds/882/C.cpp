#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], n;
int adj[1<<8];
void test(){
  memset(adj, -1, sizeof adj);
  scanf("%d", &n);
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
    mx = max(mx, a[i]);
  }
  int suf = a[n-1];
  adj[suf] = 1;
  for (int i = n-2; i >= 0; i--){
    suf ^= a[i];
    adj[suf] = 1;
  }
  
  for (int i = (1<<8) - 1; i > 0; i--){
    bool found = adj[i] == 1;
    for (int j = 0; j <= i; j++){
      if (adj[j] == 1 && adj[i ^ j] == 1)
        found = 1;
    }
    if (found)
    {
      mx = max(mx, i);
      break;
    }
  }
  printf("%d\n", mx);
}
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    test();
  }
}


/*
sufList [x, y, z]
choose x 
newSufList [x, x ^ x, x ^ y, x ^ z]
[0, x, x ^ y, x ^ z]
choose x ^ y
[x^y, x^x^y, x^y^x^y, x^y^x^z]
[x^y, y, 0, y^z]


1000
0010
0100
1100
0001
*/