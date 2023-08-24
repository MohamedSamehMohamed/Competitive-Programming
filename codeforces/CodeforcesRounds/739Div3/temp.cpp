// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
char x[N];
int n;
int lst[26];
int frq[26], nwFrq[26];
void test()
{
    scanf("%s", x);
    n = strlen(x);
    memset(lst, -1, sizeof lst);
    memset(frq, 0, sizeof frq);
    memset(nwFrq, 0, sizeof nwFrq);
    for(int i = 0; i < n; i++)
        lst[x[i] - 'a'] = i;

    vector<pair<int, int>> lstord;
    for(int i = 0; i < 26; i++)
        if (~lst[i])
            lstord.push_back({lst[i], i});
    sort(lstord.begin(), lstord.end());
    string order = "";
    for(auto c: lstord)
        order += c.second;
    int j = n-1;
    while(j >= 0 && x[j]-'a' == lstord.back().second)
    {
        frq[x[j]-'a']++;
        j--;
    }
    lstord.pop_back();
    int lstFirstCut = -1;
    bool bad = 0;
    while(!bad && lstord.size()) {
        if (lstord.size() == 1)lstFirstCut = j;
        memset(nwFrq, 0, sizeof nwFrq);
        while (j >= 0) {
            nwFrq[x[j] - 'a']++;
            j--;
            bool done = 1;
            for(int k = 0; k < 26; k++)
                if (nwFrq[k] < frq[k])
                    done = 0;
            if (done)
                break;
        }
        while(j >= 0 && x[j]-'a' == lstord.back().second)
        {
            nwFrq[x[j]-'a']++;
            j--;
        }
        frq[lstord.back().second] = nwFrq[lstord.back().second];
        for(int k = 0; k < 26; k++)
        {
            if (frq[k] != nwFrq[k])
            {
                bad = 1;
            }
        }
        lstord.pop_back();
    }

    if (bad)
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