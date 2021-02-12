// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int t ;
string x , y;
map <string , ll > mp1 , mp2 ;
void convert (string &a , bool turn )
{
    for (int i =1 ; i < SZ(a)-1 ;i++)
    {
        string key = "";
        string val = "";
        while (a[i] != ':')
        {
            key += a[i];
            i++;
        }
        i++;
        while (i < SZ(a)-1 && a[i] != ',')
        {
            val+=a[i];
            i++;
        }
        if (!turn)
        {

            mp1[key] = atol(val.c_str());
        }else
        {
            mp2[key] = atol(val.c_str());
        }
    }
}
vector<string> add , rem , change ;
void solve()
{
    add = rem = change = vector<string> ();
    mp1 = map<string,ll> ();
    mp2 = map<string,ll> ();
    convert(x,0);
    convert(y,1);
    for (auto i : mp2 )
    {
        auto j = mp1.find(i.f);
        if (j == mp1.end())
        {
            add.pb(i.f);
        }else
        {
            if (  (*j).s != i.s )
                change.pb(i.f);
        }
    }
    for (auto i : mp1 )
    {
        if (mp2.find(i.f) == mp2.end())
        {
            rem.pb(i.f);
        }
    }
    sort(all(add));
    sort(all(rem));
    sort(all(change));
}
bool printV (vector<string> &v , char start )
{
        if (SZ(v) == 0 )return 0;
        cout << start;
        for (int i =0 ; i < SZ(v) ;i++)
        {
            cout << v[i];
            if (i < SZ(v)-1 )cout << ',';
        }
        cout <<"\n";
        return 1 ;
}
int main()
{
    scanf ("%d" , &t );
    for (int i =0 ; i < t; i++)
    {
        cin >> x >> y;
        solve();
        bool ch = printV(add,'+');
        ch |= printV(rem,'-');
        ch |= printV(change,'*');
        if (!ch)cout <<"No changes\n";
        cout <<"\n";
    }
}
