#include<bits/stdc++.h>
using namespace std ;

string  fr , se , th ;
string take = "ABC";
string Out = "";
bool check (string x, string y )
{

    map<char,int>t;
    for (int i =0 ;i < 3; i++)
        t[x[i]]=1;
    if (t.size()!=3)
        return false ;
    if (y[1]=='<'){
    for (int i = 0 ; i< 3 ; i++)
    {
        if (x[i]==y[0]&&i==0)
        {
        return true ;

        }
        else if (x[i]==y[0]&&i==1)
        {
            if (x[0]==y[2])
                return false ;
            return true ;
        }
        else if (x[i]==y[0])
        return false ;
    }
    }else
    {
      for (int i = 0 ; i< 3 ; i++)
    {
        if (x[i]==y[2]&&i==0)
        {
        return true ;

        }
        else if (x[i]==y[2]&&i==1)
        {
            if (x[0]==y[0])
                return false ;
            return true ;
        }
        else if (x[i]==y[2])
        return false ;
    }
    }
}
bool Get_All (int n , string choose )
{

    if (n == 0)
    {
        Out="";
        Out =  choose ;
        if (check(Out,fr) &&check(Out,se) &&check(Out,th))
            return true ;
        else
            return false ;

    }
    else
    {

        for (int i = 0 ; i < 3 ;i++)
        {

            if ( Get_All(n-1,choose+take[i]))
                return true ;

        }


    }
    return false ;

}
int main()
{

    cin >> fr >> se >> th ;
    cout << ( Get_All(3,"") ?Out :"Impossible");
    cout << "\n";
return 0 ;
}