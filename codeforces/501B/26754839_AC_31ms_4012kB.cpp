#include<bits/stdc++.h>
using namespace std ;
/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                           MOHAMED SAMEH                             #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
typedef long long ll ;
typedef vector<int> V ;
typedef vector<ll > VL ;
typedef vector<pair<int,int> >VP;
typedef vector<pair<ll,ll > >VPL;
typedef map<int,int>  MP ;
typedef map<char,int>MCI;
typedef map<ll,ll >  MPL;
typedef set<int> ST ;
typedef stack<int>SK ;
typedef stack<pair<int,int > >SKP;
typedef queue <int> Q ;
typedef priority_queue<int> PQ ;
typedef deque<int> DQ;
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
int main()
{


    map <string , string > Old ;
    map <string , int >New ;
    int  n ;
    cin >> n ;
    string  x , y ;
    for (int i =0 ;i < n ; i++)
    {
        cin >> x >> y ;
        if ( New[y] )
            continue;
            else
            New[y]=1 ;

            if (New [x]==1)
                {

                    New[x]=0;


                    for (auto &N : Old )
                    {
                        if (N.s == x )
                            {
                                N.s = y ;
                                break;
                            }
                    }
                    New[y]=1;
                }
                else
        Old[x]=y ;
    }
    cout <<  Old.size() <<"\n";

        for (auto N : Old )
            cout << N.f << " "<< N.s <<"\n";
 return 0 ;
}
// old code 