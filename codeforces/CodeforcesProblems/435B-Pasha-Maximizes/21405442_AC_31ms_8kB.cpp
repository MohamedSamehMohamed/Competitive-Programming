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
int main()
{
    string x ;
    int k ;
    cin >> x >> k ;
    int l = 0 ;
    while (l<SZ(x)&&k&&SZ(x)>1)
    {
        int pos = l ;
        for (int i =l ; i < SZ(x) && pos - l <= k ;i++)
        {
            if (x[i] > x[pos] && i - l <= k )pos = i;
        }
        if (pos == l || x[pos] <= x[l] )
        {
            l++;
            continue ;
        }
        if (pos - l <= k && x[pos] > x[l])
        {
            k-=pos-l;
            while (pos - 1 >= l)
            {
                swap(x[pos] , x[pos-1]);
                pos--;
            }
         l++;
        }else
        {
            for (int i =0 ; k && i +1  < SZ(x) ;i++)
            {
                if (x[i] < x[i+1])
                {
                    swap(x[i] , x[i+1]);
                    k--;
                    i = -1 ;
                }
            }
        }
    }
    cout << x <<"\n";
}
