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
class CinderellaGirls
{
public :
	int count(vector<int> ta, vector<int> sk)
	{
	    int ans =0 ;
	    int n = ta.size();
	    for (int i =0 ; i < n ;i++ )
        {
            bool ok =1 ;
            for (int j = 0 ; j < n ;j++)
            {
                if (j == i )continue ;
                if ( ta[j] > ta[i] && sk[j] > sk[i])
                {
                    ok = 0 ;
                    break;
                }
            }
            ans += ok ;
        }
        return ans ;
	}
};

