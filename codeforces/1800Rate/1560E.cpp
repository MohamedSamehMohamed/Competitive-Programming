// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
char x[N];
int n;
int frq[26];
void test()
{
    scanf("%s", x);
    n = strlen(x);
    memset(frq, 0, sizeof frq);
    string order = "";
    for(int i = n-1; ~i; i--)
        if (++frq[x[i] - 'a'] == 1)
            order += x[i];
    reverse(order.begin(), order.end());
    int len = 0;
    for(int i = 0; i < order.size(); i++)
        len += frq[order[i]-'a'] / (i+1);
    string ans = "";
    for(int i = 0; i < len; i++)
        ans += x[i];
    string start = ans;
    string fin = ans;
    for(int i = 0; i < order.size(); i++)
    {
        string temp = "";
        for(int j = 0; j < start.size(); j++)
            if (start[j] != order[i])
                temp += start[j];
        fin += temp;
        start = temp;
    }
    bool ok = fin.size() == n;
    for(int i = 0; ok && i < n; i++)
        ok &= (fin[i] == x[i]);
    if (ok)
        printf("%s %s\n", ans.c_str(), order.c_str());
    else
        printf("-1\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}