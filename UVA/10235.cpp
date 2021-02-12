// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 9;
int siev[N], ans[N], n;
string str[3] = {"is emirp.", "is not prime.", "is prime."};
int rev(int x)
{
 int rx = 0, X = x;
 while(x)
 {
  rx = rx * 10 + x%10;
  x/=10;
 }
 if (rx >= N)while(1); 
 return rx == X? 0: rx; 
}
int main()
{
 siev[0] = siev[1] = 1;
 for (int i = 2; i <= N/ i; i++)
 {
  if (siev[i])continue;
  for (int j = i * i; j < N; j+=i)
   siev[j] = 1; 
 }
 for (int i = 0; i <= 1000000; i++)
 {
  if (siev[i])
   ans[i] = 1; 
  else
  ans[i] = 2 * siev[rev(i)];
 }
 while(~scanf("%d", &n))
 {
  printf("%d %s\n", n, str[ans[n]].c_str()); 
 } 
}
