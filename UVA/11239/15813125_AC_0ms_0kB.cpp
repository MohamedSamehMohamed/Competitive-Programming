// Author : Mohamed Sameh
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
////////////////////////////////////////////////////////////////////
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

map < string  , int   > Projects ;
map <string , string > Students ;
map <string , int > Block ;
string Proj_Name ;
string Stu_Name ;
bool m (pair< int , string > x , pair< int , string > y )
{
    if (x.f > y.f )
        return true ;
    else if (x.f < y.f)
        return false ;
    return ( x.s < y.s );
}
void Finsh_Print ()
{
    vector < pair < int , string > >Temp ;
    for (auto  p : Projects )
    {
        Temp.pb ({p.s , p.f });
    }
    sort (all(Temp) , m);
    for (int i= 0; i< Temp.size() ; i++)
        cout << Temp[i].s << " " << Temp[i].f << "\n";
    Projects.clear() ; Students.clear() ; Block.clear() ;
}
int main ()
{


    getline(cin , Proj_Name);
    while (1)
    {

        if ( Proj_Name == "0")
            break ;
        if ( Projects[Proj_Name] == 0 )
        {
            Projects[Proj_Name] =0 ;
        }
        while (1)
        {
            getline(cin , Stu_Name);
            if ( Stu_Name[0] >= 'A' &&Stu_Name[0] <= 'Z')
            {
                Proj_Name = Stu_Name ;
                break ;
            }
            else if ( Stu_Name[0] == '1' )
            {
                Finsh_Print () ;
                getline(cin , Proj_Name);
                break ;
            }

            if (Students[Stu_Name] == "" )
            {
                Students[Stu_Name] = Proj_Name ;
                Projects[Proj_Name]++;
            }else if (Block [Stu_Name]||Students[Stu_Name] == Proj_Name )
            {
                continue ;
            }
            else
            {
                if (Projects[Students[Stu_Name]] >= 1 )
                Projects[Students[Stu_Name]]--;
                Block[Stu_Name]=1;

            }




        }

    }

   return 0 ;
}


