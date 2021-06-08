// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n, buses, d; 
int ans[N][N]; 
/*
look at the positions of student in a column 
so the answer exist if each student has a unique column 
n student, d days 
n = 4, d = 3 
s1 s2 s3 s4
s1 s2 s3 s4
s1 s2 s3 s4
 
x x z y
y z z y
z y z y
z z z y
if each column is a unique so the answer exit 
 
*/
bool can()
{
 long long numbers = 1;
 for (int i = 0; i < d; i++)
 {
  numbers *= buses; 
  if (numbers >= n)
   return 1;
 }
 return 0; 
}
int main()
{
 scanf("%d%d%d", &n, &buses, &d);
 if (!can())
 {
  printf("-1\n"); 
  return 0; 
 }
 for (int col = 0; col < n; col++)
 {
  int number = col; 
  int p = 0;
  long long cur = 1;
  while(cur * buses <= number)
   cur *= buses, p++; 
  while(number)
  {
   while(cur > number)
     cur /= buses, p--; 
   ans[p][col] = number / cur;
   number %= cur;  
  }
 }
 for (int i = 0; i < d; i++)
  for (int j = 0; j < n; j++)
   printf("%d%c", ans[i][j]+1, (j+1==n?'\n':' ')); 
}
