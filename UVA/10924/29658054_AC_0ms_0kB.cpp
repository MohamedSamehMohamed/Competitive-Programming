// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
char str[30];
int prime(int x)
{
 for (int i = 2; i <= x/i; i++)
  if (x % i == 0)
   return 0;
 return x >= 1; 
}
void test()
{
 int sum = 0;
 for (int i = 0; str[i]; i++)
  sum += (str[i] <= 'Z'? (str[i]-'A') + 27: (str[i]-'a')+1);
 printf("%s\n", (prime(sum)? "It is a prime word.": "It is not a prime word."));
}
int main()
{
 while(~scanf(" %s", str))
  test(); 
}
