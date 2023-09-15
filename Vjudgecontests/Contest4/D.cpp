// Author : Mohamed Sameh
// created in: 10:54 PM
#include <bits/stdc++.h>
using namespace std;
bool isPrimeNumber(int num){
  if (num < 2) return 0;
  for (int i = 2; i <= num / i; i++){
    if (num % i == 0) return 0;
  }
  return 1;
}
void test(){
  // there is someone once said you can
  // construct a number by 3 prime numbers
  int n;
  scanf("%d", &n);
  if (isPrimeNumber(n)){
    printf("%d\n", 1);
    return;
  }
  // Goldbach's
  // every even natural number greater than 2 is the sum of two prime numbers
  if (n%2 == 0 || isPrimeNumber(n-2)){
    printf("%d\n", 2);
    return;
  }
  printf("%d\n", 3);
}
int main()
{
  test();
}