//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=998244353;
ll OO=1e10;
const int N=1e3 + 5,M=1e4 + 5;
//int arr[N],vis[N];
int vid;
 
ll n,m,k,cnt,SU,idx,len,MN,MX,T;
int l,r,mid;
ll a,b,c,d;
 
 
int main(){
 IO
 //freopen("kingwalk.in","r",stdin);
 //freopen("kingwalk.out","w",stdout);
 cin>>T;
 while(T--){
  cin>>b>>d;
  /*if(b%d == 0){
   cout<<b-1<<endl;
   continue;
  }*/
  d /= __gcd(b,d);
  cout<<(b-1)/d<<endl;
  
 }
 
}
 
