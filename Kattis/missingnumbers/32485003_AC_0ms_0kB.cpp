// Author: Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
bool good = 1;
int cur = 1;
for(int i = 0; i < n; i++)
{
    int x;cin >> x;
    if (x == cur)
    {
        cur++;
        continue;
    }
    while(cur < x)
    {
        cout << cur <<"\n";
        cur++;
        good = 0;
    }
    cur++;
}
if (good)
    cout <<"good job\n";
}