// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int M = 1e5 + 4 ;
int a[M];
int n;
int tree[M*4];
int tree1[M*4];
void build (int l = 0 , int r = n-1 ,int id = 0  )
{
    if (l == r )
    {
        tree[id] = a[l];
        return ;
    }
    int m = (l+r)>>1;
    build(l , m , id * 2 + 1 );
    build(m+1 , r , id * 2 + 2 );
    tree[id] = max(tree[id*2+1] , tree[id*2+2]);
}
void build1 (int l = 0 , int r = n-1 ,int id = 0  )
{
    if (l == r )
    {
        tree1[id] = a[l];
        return ;
    }
    int m = (l+r)>>1;
    build1(l , m , id * 2 + 1 );
    build1(m+1 , r , id * 2 + 2 );
    tree1[id] = min(tree1[id*2+1] , tree1[id*2+2]);
}
int qm (int l  , int r , int id , int L , int R )
{
    if (l >= L && r <= R )return tree[id];
    if (l > R || r < L )return 0 ;
    int m = (l+r)>>1;
    if (R <= m)return qm(l , m , id * 2 + 1 , L , R );
    else if (L > m )return qm(m+1 , r , id * 2 + 2 , L , R );
    return max (qm(l , m , id * 2 + 1 , L , R ) , qm(m+1 , r , id * 2 + 2 , L , R ));
}
int qn (int l  , int r  , int id  , int L , int R )
{
    //cout << l <<" " << r <<" " << L <<" " << R <<" " << tree1[id] <<"\n";
    if (l >= L && r <= R )return tree1[id];
    if (l > R  || r < L )return 1e9 ;
    int m = (l+r)>>1;
    if (R <= m)return qn(l , m , id * 2 + 1 , L , R );
    else if (L > m )return qn(m+1 , r , id * 2 + 2 , L , R );
    return min (qn(l , m , id * 2 + 1 , L , R ) , qn(m+1 , r , id * 2 + 2 , L , R ));
}
pair<int,int> mx (int l , int r )
{
    int x = qm(0 , n-1 , 0 , l , r );
    int y = qn(0 , n-1 , 0 , l , r );
    return {y , x };
}
bool ok (int len )
{
    for (int i =0 , j = len -1 ; j < n ; j++,i++)
    {
        pair<int,int> x = mx(i , j );
        //cout << i+1 <<" " << j+1 <<" " << x.f <<" " << x.s <<"\n";
        if (x.s - x.f <= 1 )return 1 ;
    }
    return 0 ;
}
int main()
{
scanf ("%d" , &n );
for (int i =0 ; i < n ;i++)scanf ("%d" ,a+i);
build();
build1();
//cout << mx(1,2).f <<" " << mx(1,2).s <<"\n";
//return 0;
int l = 1, r = n , m , ans = 1;
while (l <= r )
{
    m = (l+r)>>1;
    if (ok(m))
    {
        ans = m ;
        l = m+1;
    }else
    r = m-1 ;
}
printf ("%d\n" ,ans );
}
