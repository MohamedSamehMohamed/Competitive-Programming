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
class ThreePartSplit
{
public :
vector<int> split(int a, int d)
{
    int sp = (d-a+1)/3 ;
    return {a + sp , a + sp + sp };
}
};
