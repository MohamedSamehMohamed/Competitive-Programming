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
    int in =0 ;
    int rm =0 ;
    for (int i =0 ; i < SZ(x) ;i++)
    {
        if (x[i] == '(')in++;
        else
        {
            if (in)in--;
            else
                rm++;
        }
    }

    cout << SZ(x) - rm - in <<"\n";
     return 0;
}
