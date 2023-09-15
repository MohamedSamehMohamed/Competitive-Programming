#include <bits/stdc++.h>
using namespace std;
int n; 
string arr[200];
int x[200][200];
 
bool valid(int u,int v){
 bool flage = true;
 for(int j=v+1;j<n;++j)
  flage &= (x[u][v] != x[u][j]);
 for(int j=0;j<v;++j)
  flage &= (x[u][v] != x[u][j]);
 
 for(int j=u+1;j<n;++j)
  flage &= (x[u][v] != x[j][v]);
 for(int j=0;j<u;++j)
  flage &= (x[u][v] != x[j][v]);
 return flage; 
}
 
bool solve2()
{
 bool flage = true;
 for(int i=0;i<n;++i)
  for(int j=0;j<n;++j)
   flage &= valid(i,j);
 for(int i=0;i<n;++i){
  sort(x[i],x[i]+n);
  for(int j=0;j<n;++j)
   flage &= (x[i][j] == j);
 }
 return flage;
 
}
bool solve1(){
 for (int i = 1; i < n; i++)
 {
  if (x[0][i] <= x[0][i-1])
   return 0;
  if (x[i][0] <= x[i-1][0])
   return 0; 
 }
 return 1; 
}
int main()
{
 
 ios::sync_with_stdio(0);
    cin.tie(0);
    
 while (cin >> n){
 for (int i = 0; i < n; i++)
  cin >> arr[i];
 for(int i=0;i<n;++i){
  for(int j=0;j<n;++j){
   if(arr[i][j] >='0' && arr[i][j] <= '9')
    x[i][j] = arr[i][j] - '0';
   else
    x[i][j] = arr[i][j] - 'A' + 10;
  }
 }
 bool inc = solve1(); 
 bool Uni = solve2(); 
 if (inc && Uni)
  cout << "Reduced\n"; 
 else if (Uni && !inc)
 {
  cout << "Not Reduced\n"; 
 }else 
  cout << "No\n";
 }
}
 
/*
3
012
120
201
 
 
*/
