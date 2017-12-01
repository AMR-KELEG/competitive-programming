/* AC
Sprague Grundy + Patterns
*/
#include "bits/stdc++.h"
using namespace std;

int solve(int n,int b)
{
	if (n==0)
		return 0;
	if (b==1)
		return !solve(n-1,b);
	set<int>ch;
	int rem = 1;
	while(rem<=n)
	{
		ch.insert(solve(n-rem,b));
		rem *=b;
	}
	for (int r=0;r<50;r++)
	{
		if (ch.find(r)==ch.end())
			return r;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
		freopen("powers.in","r",stdin);
	#endif
	int T;
	cin>>T;
	// for (int b=0;b<11;b+=2)
	// {
	// 	if (b==0)
	// 	{
	// 		cout<<setw(5)<<"   ";
	// 		for (int i=0;i<22;i++)
	// 		{
	// 			cout<<setw(3)<<i<<" ";
	// 		}
	// 		cout<<endl;
	// 		continue;
	// 	}
	// 	cout<<setw(3)<<b<<": ";
	// 	for (int i=0;i<22;i++)
	// 	{
	// 		cout<<setw(3)<<solve(i,b)<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// return 0;
	while(T--)
	{
		int g;
		cin>>g;
		int b,n;
		long long int sg_val = 0;
		for (int i=0;i<g;i++)
		{
			cin>>b>>n;
			if (b%2)
			{
				sg_val ^= (n%2);
			}
			else
			{
				int mod_val = n%(b+1);
				if (mod_val == b)
				{
					sg_val ^=2;	
				}
				else
				{
					sg_val ^=mod_val %2;	
				}
			}
		}
		if (sg_val)
			printf("1\n");
		else
			printf("2\n");
	}	
}