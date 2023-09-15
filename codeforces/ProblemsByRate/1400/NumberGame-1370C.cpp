#include <bits/stdc++.h>
bool isPrime(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  for (int i = 3; i <= n / i; i += 2)
    if (n % i == 0) return 0;
  return 1;
}
using namespace std;
void test(){
  int n;
  scanf("%d", &n);
  if (n == 1){
    printf("FastestFinger\n");
  }else if (n % 2 == 1 || n == 2)
    printf("Ashishgup\n");
  else {
    if ((n & (n-1))==0){
      printf("FastestFinger\n");
    }else {
      int twoCnt = 0;
      while (n % 2 == 0)
      {
        twoCnt++;
        n /= 2;
      }
      bool ok = 1;
      if (twoCnt == 1){
        if (isPrime(n))
          ok = 0;
      }
      if (ok)
        printf("Ashishgup\n");
      else
        printf("FastestFinger\n");
    }
  }
}

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}