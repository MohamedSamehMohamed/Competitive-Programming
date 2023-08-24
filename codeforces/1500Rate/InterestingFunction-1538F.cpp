#include <bits/stdc++.h>
using namespace std;
int l, r;
int numberOfChanges(int number){
  int total = 0, b = 1;
  while (number){
    int d = number % 10;
    total += d * b;
    b = b * 10 + 1;
    number /= 10;
  }
  return total;
}
int count (int a, int b){
  int cnt = 0;
  while (a && b){
    cnt += (a % 10) != (b % 10);
    a /= 10;
    b /= 10;
  }
  if (a != b) cnt++;
  return cnt;
}
int count(){
  int cnt = 0;
  for (int i = l + 1; i <= r; i++){
    cnt += count(i-1, i);
  }
  return cnt;
}
void test(){
  scanf("%d%d", &l, &r);
  int total = numberOfChanges(r) - numberOfChanges(l);
  printf("%d\n", total);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}