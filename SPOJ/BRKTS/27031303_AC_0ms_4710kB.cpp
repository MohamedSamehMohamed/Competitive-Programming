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
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		bool good = 1;
		string x;
		cin >> x;
		int op = 0;
		for (int i = 0; i < SZ(x); i++)
		{
			if (x[i] == '{')op++;
			else 
			{
				if (op)op--;
				else 
				{
					good = 0;
				}
			}
		}
		good &= (op == 0);
		cout << (good? ":)" : ":(") << '\n';
	}
}
