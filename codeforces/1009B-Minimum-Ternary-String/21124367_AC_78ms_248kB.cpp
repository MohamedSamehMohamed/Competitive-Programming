// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
void fo ()
{
    fflush(stdout);
}
using namespace std ;
int main ()
{
    string x ;
    cin >> x;
    int one =0 ;
    for (int i =0 ; i < SZ(x) ;i++)one+=(x[i] == '1' );
    for (int i =0 ; i < SZ(x) ;i++)
    {
        while (i < SZ(x) && x[i] != '2')
        {
            if (x[i] == '0')cout << 0;
            i++;
        }
        while (one--)cout << 1;
        while (i < SZ(x))
        {
            if (x[i] != '1')
            cout << x[i];
            i++;
        }
    }
    return 0;
}
