// Author : Mohamed Sameh
// created in: 4:21 PM
#include <bits/stdc++.h>
using namespace std;

void test(){
 string s;
 cin >> s;
 for (int i = 0; i < 3; i++){
   for (int j = 0; j < 3; j++){
     string x = s;
     swap(x[i], x[j]);
     if (x == "abc"){
       cout <<"YES\n";
       return;
     }
   }
 }
 cout <<"NO\n";
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}