// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
char x[N];
int n;
int lst[26];
int frq[26], nwFrq[26];
int mainFrq[26];
void test()
{
    scanf("%s", x);
    n = strlen(x);
    memset(mainFrq, 0, sizeof mainFrq);
    memset(lst, -1, sizeof lst);
    memset(frq, 0, sizeof frq);
    memset(nwFrq, 0, sizeof nwFrq);
    for(int i = 0; i < n; i++)
        lst[x[i] - 'a'] = i, mainFrq[x[i] - 'a']++;
    string orign = "";
    vector<pair<int, int>> lstord;
    for(int i = 0; i < 26; i++)
        if (~lst[i])
            lstord.push_back({lst[i], i});
    sort(lstord.begin(), lstord.end());
    string order = "";
    for(auto c: lstord)
        order += c.second + 'a';
    if (order.size() == 1)
    {
        printf("%s %c\n", x, x[0]);
        return;
    }
    int j = n-1;
    while(j >= 0 && x[j]-'a' == lstord.back().second && frq[x[j]-'a'] * lstord.size() != mainFrq[x[j] - 'a'])
    {
        frq[x[j]-'a']++;
        orign += x[j];
        j--;
    }
    lstord.pop_back();
    int lstFirstCut = -1;
    bool good = 1;
    while(j >= 0 && good && lstord.size()) {
        if (lstord.size() == 1)lstFirstCut = j;
        memset(nwFrq, 0, sizeof nwFrq);
        int pos = 0;
        string norign = "";
        while (j >= 0 && pos < orign.size() && ( x[j]  - 'a' == lstord.back().second || x[j] == orign[pos]) ) {
            nwFrq[x[j] - 'a']++;
            norign += x[j];
            if (x[j] == orign[pos])
                pos++;
            j--;
        }
        if (pos != orign.size())
        {
            good = 0;break;
        }
        while(j >= 0 && x[j]-'a' == lstord.back().second && mainFrq[x[j]-'a'] != lstord.size() * nwFrq[x[j] - 'a'])
        {
            nwFrq[x[j]-'a']++;
            norign += x[j];
            j--;
        }
        frq[lstord.back().second] = nwFrq[lstord.back().second];
        for(int k = 0; k < 26; k++)
        {
            if (frq[k] != nwFrq[k])
            {
                good = 0;
            }
        }
        orign = norign;
        lstord.pop_back();
    }
    good &= (j < 0);
    if (good)
    {
        for(int i = 0; i < lstFirstCut+1; i++)
            printf("%c", x[i]);
        printf(" ");
        printf("%s\n", order.c_str());
    }else
        printf("-1\n");
}
int main()
{

    int t;
    scanf("%d", &t);
    while(t--)
        test();
}