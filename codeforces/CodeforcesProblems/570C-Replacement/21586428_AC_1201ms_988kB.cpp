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
int n , m ;
string x ;
int main()
{
cin >> n >> m >> x ;
int ans =0 ;
for (int i =0 ; i < n ;i++)
{
    if (x[i] != '.')continue ;
    int j = i+1 ;
    while (j < n && x[j] =='.')j++;
    ans += j-i-1 ;
    i = j-1 ;
}
while (m--)
{
    int id ;
    char c ;
    cin >> id >> c ;
    id--;
    if (c == '.')
    {
        if (x[id] != '.')
        {
            x[id] = '.';
            if (id-1 >= 0 && id+1 < n && x[id-1] =='.' && x[id+1] == '.')
            {
                ans+=2;

            }else if ((id+1 < n && x[id+1] =='.' )|| (id-1 >= 0 && x[id-1] =='.') )
            {
                ans++;
            }
        }
    }else
    {
        if (x[id] == '.')
        {
            x[id] = c ;
            if (id-1 >= 0 && id+1 < n && x[id-1] =='.' && x[id+1] == '.')
            {
                ans-=2;

            }else if ((id+1 < n && x[id+1] =='.' )|| (id-1 >= 0 && x[id-1] =='.') )
            {
                ans--;
            }
        }
    }
    printf ("%d\n" ,ans );
}

}
