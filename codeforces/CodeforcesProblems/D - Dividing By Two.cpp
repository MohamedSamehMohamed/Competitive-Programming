#include<bits/stdc++.h>
using namespace std;
 
int a,b;
 
int Solve(int a,int b){
 
 if(a <= b)
  return b - a;
 if(a&1)
  return 1 + Solve(a+1,b);
 return 1 + Solve(a/2,b);
  
}
 
 
int main(){
 scanf("%d%d",&a,&b);
 printf("%d\n",Solve(a,b)); 
 
}
