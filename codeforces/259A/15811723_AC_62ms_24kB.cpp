#include<bits/stdc++.h>
using namespace std ;

bool ch (string x )
{
    for (int i =0 ;i+1 < 8 ; i++)
        if (x[i]==x[i+1])
            return true ; 
            
            return false ; 
}
int main()
{
    bool ok = 1 ; 
    string x ;
    for (int i=0 ;i < 8 ;i++)
    {
        int w = 0 , b =0 ; 
        cin >>x; 
        for (int j =0 ; j < 8 ; j++)
            if (x[j]=='B')
                b++;
                else 
                w++; 
                    
        if (  w!=b || ch(x) )
            {
                ok =0;
                break ; 
            }
        
    }
    cout << (ok ? "YES\n":"NO\n"); 
    return 0;
}