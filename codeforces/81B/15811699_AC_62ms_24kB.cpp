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
void RemoveSpaces (string t1 , string &t2 )
{

    for (int i =0 ;i < t1.size() ; i++)
    {
        if (t1[i] == ' ')continue ;
        t2+=t1[i] ;
    }
}
string  Modify (string t  )
{
    // 1,2,3,...,10

    int NumOfNums = 0;
for (int i =0 ;i < t.size() ; i++){
 if (t[i] >= '0' && t[i] <= '9')
          {
              NumOfNums++;

              if (i+1 < t.size() && t[i+1] >= '0' && t[i+1] <= '9')
              {
                  i++;
                  i++;
                    for (;i<t.size() ; )
                        if ( t[i] >= '0' && t[i] <= '9' ){i++;}
                            else
                    {
                        i--;
                        break ;
                    }



              }


          }
}

    string t1 = "";
    char c1 = ',' , c2 = ' ';
    string c3 = " ...";
    bool PreNum = 0 ;
    for (int i =0 ; i < t.size() ; i++)
        {
            if (t[i] >= '0' && t[i] <= '9')
          {
              string Temp = "";
              Temp+=t[i];
              if (i+1 < t.size() && t[i+1] >= '0' && t[i+1] <= '9')
              {
                  Temp+=t[++i];
                  i++;
                    for (;i<t.size() ; )
                        if ( t[i] >= '0' && t[i] <= '9' ){Temp+=t[i];i++;}
                            else
                    {
                        i--;
                        break ;
                    }



              }
              if (PreNum)t1+=c2 ;
              t1+=Temp;

              PreNum=1 ;

          }
        else if (t[i] == ',')
            {
                t1+=t[i];
                t1+=c2;
                PreNum=0;
            }
        else if (t[i] != ' ')
            {

                t1+=t[i];
                PreNum=0 ;
            }

        }

        string t2 = "";

        for (int i =0 ;i <  t1.size() ; i++)
        {
            if (t1[i] == '.')
            {
                t2+=c3 ;
                i+=2;
            }else
            t2+=t1[i];
        }
        t1 = "";
        c1 = '1';
        for (int i =0 ; i < t2.size() ; i++){

            if (t2[i] == ' ' && (i == 0 || i == t2.size()-1 ))
                continue ;
            else if (t2[i] == ' '&&c1 == ' ')
                continue ;
            else if (t2[i] != ' ')
            {
                t1+=t2[i];
                c1='1';
            }else if (t2[i] == ' ' && c1 =='1')
            {
                t1+=t2[i];
                c1=' ';
            }


        }


        return t1 ;
}
int main ()
{


    string t , Text = "";
    getline( cin ,  Text );
    //RemoveSpaces(t,Text);
    Text = Modify(Text);
    cout << Text <<"\n";
   return 0 ;
}

