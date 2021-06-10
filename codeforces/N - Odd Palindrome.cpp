#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=3e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
string s;
 
 
int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    cin>>s;
    bool va=0;
    for(int i=0;i<s.length()-1;++i)
        if(s[i]==s[i+1]) va=1;
    if(va) printf("Or not.\n");
    else printf("Odd.");
    return 0;
}
