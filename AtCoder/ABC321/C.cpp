// Author : Mohamed Sameh
// created in: 2:06 PM
#include <bits/stdc++.h>
using namespace std;
void test(){
  int k;
  cin >> k;
  queue<string> q;
  vector<string> str;

  set<string> take;
  string mp = "0123456789";
  for(int i = 1; i <= 9; i++){
    string cur = "";
    cur += mp[i];
    q.push(cur);
    take.insert(cur);
    str.push_back(cur);
  }

  while (!q.empty()){
      string cur = q.front();
      q.pop();
      int lst = cur.back() - '0';
      for (int i = lst-1; i >= 0; i--){
        string to = cur;
        to += mp[i];
        if (take.count(to) == 0){
          take.insert(to);
          q.push(to);
          str.push_back(to);
        }
      }
  }
  auto toInt = [&](string a){
    long long number = 0;
    for (int i = 0; i < a.size(); i++)
      number = number * 10 + (a[i] -'0');
    return number;
  };
  sort(str.begin(), str.end(), [&](string a, string b){
    return toInt(a) < toInt(b);
  });
  cout << str[k-1] <<"\n";
}
int main()
{
  test();
}