// Author : Mohamed Sameh
// created in: 8:28 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int n;
  cin >> n;
  set<string> st;
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    st.insert(s);
  }
  for(auto i: st){
    if (i[0] == '!')
    {
      if (st.count(i.substr(1))){
        cout << i.substr(1) << "\n";
        return;
      }
    }

  }
  cout << "satisfiable\n";
}
int main()
{
  test();
}