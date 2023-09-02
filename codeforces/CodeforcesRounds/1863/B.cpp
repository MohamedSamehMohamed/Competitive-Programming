// Author : Mohamed Sameh
// created in: 4:51 PM
/*
 * 10 19 7 1 17 11 8 5 12 9 4 18 14 2 6 15 3 16 13
  min(a[0:a[1]])
   1 5 4 2 6 3 10 19 7 17 11 8 12 9 18 14 15 16 13
   6 4 3 5 2 1
   1 6 4 3 5 2
   1 2 6 4 3 5
   1 2 3 6 4 5

   1 2 5 4 3 6

   1 2 3 4 5 6



 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N], n;
void applay(int mn){
  int j = 0;
  for (int i = 0; i < n; i++){
    if (a[i] < mn){
      b[j++] = a[i];
    }
  }
  for (int i = 0; i < n; i++){
    if (a[i] >= mn)
      b[j++] = a[i];
  }
  for (int i = 0; i < n; i++)
    a[i] = b[i];
}
int exist[N];
void test(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i <= n; i++)exist[i] = 0;
  exist[0] = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (exist[a[i] - 1])
      cnt++;
    exist[a[i]] = 1;
  }
  printf("%d\n", n - cnt);

}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}