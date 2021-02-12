// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
char x[N], y[N];
int main()
{
 scanf(" %s %s", x, y); 
 int l1, l2, r1, r2;
 l1 = l2 = 0;
 r1 = strlen(x)-1;
 r2 = strlen(y)-1;
 while(l1 <= r1 && l2 <= r2 && x[l1] == y[l2])l1++,l2++;
 while(r1 >= l1 && r2 >= l2 && x[r1] == y[r2])r1--,r2--;
 printf("%d\n", r2-l2+1); 
}
