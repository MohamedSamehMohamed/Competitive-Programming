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
vector <string>Possible ;
void  GetAllPossible (int n , string Guss )
{
if (Guss.size() == n)
{
        Possible.pb(Guss);

}
else
{

    GetAllPossible(n,Guss+"7");
    GetAllPossible(n,Guss+"4");

}

}
string Rev(string t )
{
    string t1 = "";
    for (int i = t.size() -1 ; i >= 0 ; i--)
        t1+=t[i];
    return t1 ;
}
string  Convert (int n )
{
    string t ="" ;
    string num = "0123456789";
    while (n>0)
    {
        t+=num [(n%10)]  ;
        n/=10 ;
    }
    return  Rev(t);


}
ll GetNum(string t )
{
ll Num = 0;
int k = 1 ;
t = Rev(t);
for (int i =0 ;i < t.size() ;i++,k*=10)
{
ll tem = (int (t[i] - '0'));
tem*=(ll)k;
Num+=tem ;
}
return Num ;
}
int main ()
{


ll Sum = 0 ;
int l , r ;
cin >> l >> r ;
int mx = 10 ;
int mn = Convert(l).size() ;
for (int i =mx  ; i >= mn  ; i--)
GetAllPossible(  i , "");
vector <ll>Numbers ;
for (int i =0 ;i < Possible.size()   ;i ++)
Numbers.pb (  GetNum(Possible[i]) );
sort ( all (Numbers) );

mx = Numbers.size() ;



for (int i =0 ;i <mx;i++)
{
    int left = l , right = r , m ;
    int numof =0 ;
    while (left<=right)
    {
         m = (left+right) / 2 ;
        if (m == Numbers[i])
        {

            numof = m-l+1 ;
            break ;
            left = m + 1 ;
        }
        else if (m < Numbers[i])
        {
            numof = m-l+1 ;
            left = m + 1 ;

        }
        else
            right = m - 1 ;
    }
    l+=numof ;
    Sum+= (ll)numof*Numbers[i];
}
cout << Sum << "\n";


   return 0 ;
}