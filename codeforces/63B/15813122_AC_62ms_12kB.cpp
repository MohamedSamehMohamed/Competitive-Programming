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
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int main ()
{


int n , k ;
cin >> n >> k;
int A[n];
bool done = 1 ;
for (int i =0 ;i < n ;i ++){
        cin >> A[i];
        if (A[i] < k)
            done = 0 ;
}
if (done)cout << 0 << "\n";
else
{
    int steps =0 ;
    sort (A, A+n);
    while (!done)
    {
        steps++;

     map <int,int>frq ;
     set<int>Num ;
     int Tem [n];
     for (int i =0 ;i < n ;i ++ ){frq[A[i]]++; Num.insert(A[i]);Tem[i] = A[i];}

     for (int a : Num)
     {

         int sz = frq [a];
         if (sz != 1 )
            sz = 1 ;


         for (int j =0 ;j < n && sz; j++)
         {
            if (A[j] == a)
            {
                if (Tem[j] + 1 <= k)
                Tem[j]++;
                sz--;
            }
         }

     }
     bool ok = 1 ;
     for (int i =0 ;i < n ; i++){A[i] = Tem[i]; if (Tem[i] < k) ok =0 ;}

    if (ok)break ;


    }
    cout << steps << "\n";



}

    return 0 ;
}