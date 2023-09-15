// Author : Mohamed sameh
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
const int N = 1e6+9;
string x;
int n;
int pre[N];
void KMP()
{
	cin >> x;
	n = SZ(x);
	pre[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int j = pre[i-1];
		while(j > 0 && x[j] != x[i])j = pre[j-1];
		pre[i] = j + (x[j] == x[i]);
	}
	//for (int i = 0; i < n; i++)cout << pre[i] <<" \n"[ i == n-1];
}
int main()
{
	KMP();
	bool can = 0;
	for (int i = 1; i < n-1; i++)
		if (pre[i] == pre[n-1])
			can = 1;
	if (pre[n-1] == 0)
	{
		cout << "Just a legend\n";
		return 0;
	}
	if (can && pre[n-1])
	{
		cout << x.substr(n-pre[n-1]) << '\n';
		return 0;
	}
	if (pre[n-1]-1 > -1 && pre[pre[n-1]-1] == 0)
	{
		cout << "Just a legend\n";
		return 0;
	}
	cout << x.substr(0,pre[pre[n-1]-1]) << '\n';
}
