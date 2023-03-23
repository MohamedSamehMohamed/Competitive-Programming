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

float  distance (int x1 , int y1 , int x2 , int y2 )
{
    return  ( sqrt((float) (pow (x1 - x2, 2 )) +(float) ( pow (y1 - y2, 2 )) ) ) ;

}

int main ()
{

    map <pair <int , int >  ,  int > Taken ;
    vector < pair < int , int > >Generals ;
    vector < pair < pair <int ,int >, int  > > Fire ;
    int x1 , x2 , y1 , y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    for (int i = min (y1,y2) ; i <= max (y1,y2) ; i++ )
    {
        if (!Taken [{x1 , i }]){
        Generals.pb ( {x1 , i} );
        Taken [{x1 , i }] =1 ;
        }
        if (!Taken [{x2 , i }]){
        Generals.pb ({x2 , i} );
        Taken [{x2 , i }] =1 ;
        }
    }
     for (int i = min (x1,x2) ; i <= max (x1,x2) ; i++ )
    {
        if (!Taken [{i , y1 }]){
        Generals.pb ( {i , y1} );
        Taken [{i , y1 }] =1 ;
        }

        if (!Taken [{i , y2 }]){
        Generals.pb ({i , y2} );
        Taken [{i , y2 }] =1 ;
        }

    }
    int n  , S;
    cin >> n ;
    S = Generals.size() ;
    for (int i =0 , j ,k,l ;i < n ;i ++)
    cin >> j >> k >> l  ,Fire.pb ( { {j,k},l }  );

    sort ( all (Generals));
    for (int i =0 ;i < Generals.size() ; i++)
    {

        bool Good = 0 ;
        for (int j =0 ; j < Fire.size() ; j++)
        {

            if (    distance(Generals[i].f , Generals[i].s , Fire[j].f.f , Fire[j].f.s ) <= (float)Fire[j].s    )
            {

                Good = 1 ;
                break ;
            }
        }
        if (Good)
            S-- ;

    }

cout << S << "\n";

   return 0 ;
}
