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
int arr[N],nxt[N];
int dp[N][N];
 
ll n,m,k,cnt,SU,idx,len,MN,MX,T;
int l,r,mid;
 
void valid(){
 int v = n;
 int val = arr[n-1];
 for(int i=n-1;~i;--i){
  if(arr[i] == val)
   nxt[i] = v;
  else{
   val = arr[i];
   v = i+1;
   nxt[i] = v;
  }
 }
}
 
int Solve(int idx,int rem){
 if(!rem)
  return 1;
 if(idx >= n)
  return 0;
 int &ret = dp[idx][rem];
 if(~ret)
  return ret;
 ret = Solve(idx+1,rem);
 ret %= MOD;
 ret += Solve(nxt[idx],rem-1);
 ret %= MOD;
 return ret;
}
 
 
 
 
int main(){
 IO
 //freopen("kingwalk.in","r",stdin);
 //freopen("kingwalk.out","w",stdout);
 cin>>n>>k;
 for(int i=0;i<n;++i)
  cin>>arr[i];
 sort(arr,arr+n);
 valid();
 memset(dp,-1,sizeof(dp));
 cout<<Solve(0,k)<<endl;
  
 
}
 
 
