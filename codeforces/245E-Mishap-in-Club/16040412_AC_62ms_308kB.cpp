// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

int main ()
{
    string T ;
    cin >> T ;
    int come = 0 , out = 0;
    int Ans = 0;
    for (int i =0  ; i < T.size() ; i++)
    {
        if (  T[i] == '+'  )
        {
                if ( out == 0 )
                {
                    come++;
                    Ans ++;
                }else
                {
                    out--;
                    come++;
                }

        }else
        {
            if (come == 0  )
                {
                    out ++;
                    Ans ++;
                }else
                {
                    come--;
                    out++;
                }
        }
    }
    cout << Ans <<"\n";
   return 0 ;
}
