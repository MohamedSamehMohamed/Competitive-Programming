// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
using namespace std ;
class MilkConsumption
{

public :
vector <int> findMaxRegion(vector <int> p, vector <int> t)
{
    int ans = 0 ;
    for (int i = 1; i < SZ(p) ; i++)
    {
        double cur = 1.0*t[i] / p[i];
        double prv = 1.0*t[ans] / p[ans];
        if (cur > prv )ans = i ;
    }
    return {ans};

}

};
