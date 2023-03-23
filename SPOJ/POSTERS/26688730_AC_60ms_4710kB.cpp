
/*
this solution from github becasue the author write incorrect code and I can't write that D:
*/
#include <bits/stdc++.h>
using namespace std;



#define gc getchar unlocked
#ifndef ONLINE JUDGE
#define gc getchar
#endif // ONLINE JUDGE

#define pc putchar_unlocked
#ifndef ONLINE JUDGE
#define pc putchar
#endif // ONLINE JUDGE

#define LL long long

int fx[] = {+1,-1,+0,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,+0,+1,-1,+1,-1,+1,-1,+0};

/*---------------------------fast I/O------------------------------------*/

#define scani2(a,b) scani(a) , scani(b)
#define scani3(a,b,c) scani(a), scani(b), scani(c)
#define scani4(a,b,c,d) scani(a), scani(b), scani(c), scani(d)
#define scanL2(a,b) scanL(a), scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)


void scani(int &n)
{
    n = 0;
    char c = 0;
    while(c < 33) c = gc();
    while(c > 33)
    {
        n = n*10 + c-48;
        c = gc();
    }
}

void scanin(int &n)
{
    n = 0;
    bool negative = false;
    char c = gc();
    while( c < '0' || c > '9')
    {
        if(c == '-') negative = true;
        c = gc();
    }
    while(c >= '0' && c <= '9')
    {
        n = n*10 + c-48;
        c = gc();
    }
    if(negative) n = ~(n-1);
}

void scanL(LL &n)
{
    n = 0;
    bool negative = false;
    char c = gc();
    while( c < '0' || c > '9')
    {
        if(c == '-') negative = true;
        c = gc();
    }
    while(c >= '0' && c <= '9')
    {
        n = n*10 + c-48;
        c = gc();
    }
    if(negative) n = ~(n-1);
}

void write(int n,bool line = true)
{
//    pc(' ');
    if(n<0) {
        pc('-');
        n = -n;
    }
    if(!n) {
        pc('0');
        if(line) pc('\n');
        return;
    }
    char buff[12];
    int len = 0;
    while(n) buff[len++] = n%10+48 , n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    if(line) pc('\n');
}

void writeL(LL n,bool line = true)
{
//    pc(' ');
    if(n<0) {
        pc('-');
        n = -n;
    }
    if(!n) {
        pc('0');
        if(line) pc('\n');
        return;
    }
    char buff[22];
    int len = 0;
    while(n) buff[len++] = n%10+48 , n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    if(line) pc('\n');
}

int scans(char *a)
{
    int i=0;
    char c = 0;
    while(c < 33) c = gc();
    while(c > 33)
    {
        a[i++] = c;
        c = gc();
    }
    a[i] = 0;
    return i;

}

int uq[80008];
int x[40004];
int y[40004];
int wall[40004];
bool visited[40004];

int unify(int *in,int n)
{
    sort(in,in+n);
    int k = 0;
    for(int i=1;i<n;i++)
        if(in[i] != in[k]) in[++k] = in[i];
    return k+1;
}

int bn_search(int high , int x)
{
    high--;
    int low = 0;
    int mid;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(uq[mid] == x ) return mid;
        else if(uq[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
}

int main()
{
    int t;
    scani(t);
    while(t--)
    {
        int n,k;
        scani(n);
        k = 0;
        for(int i=0;i<n;i++)
        {
            scani2(x[i],y[i]);
            uq[k++] = x[i];
            uq[k++] = y[i];
        }
        k = unify(uq,k);
//        for(int i=0;i<k;i++) printf("%d ",uq[i]); puts("");
        for(int i=0;i<n;i++)
        {
            int low  = bn_search(k , x[i]);
            int high = bn_search(k , y[i]);
//            printf("-->> %d %d\n",low,high);
            for(int j=low;j<=high;j++)
                wall[j] = i;
        }
//        for(int i=0;i<k;i++) printf("%d ",wall[i]); puts("");
        memset(visited,false,sizeof(visited));
        int ans = 0;
        for(int i=0;i<k;i++)
        {
            int poster = wall[i];
//            printf("%d ",poster);
            if(visited[poster]) continue;
            visited[poster] = true;
            ans++;
        }
//        puts("");
        write(ans);
    }
    return 0;
}