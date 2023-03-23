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
class NBAFinals
{
public :
int dubsAgain(vector<int> sc , string team)
{
    for (int i =0 ; i < SZ(sc) ; i++)
    {
        if (sc[i] == 0 || team[i] == '?')
        {
            if (sc[i] == 0 && team[i] == '?')
            {
                team[i] = 'W';
                sc[i] = 4 ;
            }else if (sc[i] == 0 )
            {
                if (team[i] == 'W')sc[i] = 4 ;
                else
                    sc[i] =1 ;
            }else
            {
                team[i] = 'W';
            }
        }
    }
    int W , R ;
    W = R = 0;
    for (int i =0 ; i < SZ(sc) ;i++)
    {
        if (team[i] == 'W')W+=sc[i];
        else
            R += sc[i];
    }
    return W > R ;
}
};
