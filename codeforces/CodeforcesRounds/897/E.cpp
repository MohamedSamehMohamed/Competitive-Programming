// Author : Mohamed Sameh
// created in: 6:02 PM
#include <bits/stdc++.h>
using namespace std;
int n, k;
int ask(int index){
  cout << "? " << index << endl;
  int x;cin >> x;
  return x;
}
void test(){
  cin >> n >> k;
  int xo = 0;
  int index = n - k + 1;
  while (index >= 1){
    xo ^= ask(index);
    index -= k;
  }
  if (index == 1 - k){
    cout << "! " << xo << endl;
    return;
  }
  index += k;
  for (int i = 1; i < index; i++){

  }

}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}