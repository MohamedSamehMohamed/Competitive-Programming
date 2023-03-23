// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
////////////////////////////////////////////////////////////////////
#define pf push_front
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define M_P make_pair
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int main ()
{

bool done =1 ;
map<char, int >S ;
string a ;
getline(cin,a);
for (int i =0 ;i < a.size() ; i++)
{
    if (a[i]==' ')
        continue ;
    S[  a[i] ]++;
}
getline(cin,a);
for (int i =0 ;i < a.size() ; i++)
{
    if (a[i]==' ')
        continue ;
    if ( S[  a[i] ]  != 0 )
        S [  a[i] ]--;
    else
    {
        done = 0 ;
        break;
    }
}
if (done)
    cout << "YES\n";
else
    cout << "NO\n";

    return 0 ;
}