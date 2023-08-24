// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a, b;
string x;
int ar[N];
int main()
{
    cin >> x >> a >> b;
    ar[x.size()-1] = (x.back() - '0')%b;
    int curP = 10;
    for(int i = x.size()-2; i >= 0; i--)
    {
        ar[i] = ((1LL * curP * (x[i]-'0')) + ar[i+1]) % b;
        curP = (curP * 10) % b;
    }
    int cur = 0;
    curP = 1;
    for(int i = 0; i + 1< x.size(); i++)
    {
        cur = ((1LL  * cur * 10) + (x[i] - '0'))%a;
        if (x[0] != '0' && x[i+1] != '0' && cur == 0 && ar[i+1] == 0)
        {
            cout << "YES\n";
            cout << x.substr(0, i+1) << "\n";
            cout << x.substr(i+1) << "\n";
            return 0;
        }
    }
    cout <<"NO\n";
}