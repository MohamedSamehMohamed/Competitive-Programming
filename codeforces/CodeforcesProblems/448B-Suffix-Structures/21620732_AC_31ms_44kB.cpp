// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
string x , y ;
int frq[26];
int frq1[26];
int dp[101][101];
int solve (int id = 0 ,int last = 0  )
{
    if (last == SZ(y))return 1 ;
    if (id >= SZ(x))return 0 ;
    int &ret = dp[id][last];
    if (~ret)return ret ;
    ret = max (ret , solve(id + 1 , last ));
    if (x[id] == y[last])return ret = max ( solve(id + 1 , last + 1 ), ret );
    return ret ;
}
int main()
{
    cin >> x >> y ;
    for (int i =0 ; i < SZ(x) ;i++)frq[x[i]-'a']++;
    for (int i =0 ; i < SZ(y) ;i++)frq1[y[i]-'a']++;
    bool rm =0 ;
    for (int i =0 ; i < 26 ;i++)
    {
        if (frq[i] > frq1[i])rm = 1 ;
        else if (frq[i] < frq1[i])
        {
            cout <<"need tree\n";
            return 0;
        }
    }
    if (!rm)
    {
        printf ("array\n");
    }else
    {
        memset(dp , -1 ,sizeof dp );
        if (solve()== 1 )
        {
            if (!rm)
            printf ("array\n");
            else
                printf("automaton\n");
        }else
        printf ("both\n");
    }
}
