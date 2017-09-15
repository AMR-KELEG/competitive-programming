//AC
#include "bits/stdc++.h"
using namespace std;
std::vector<vector<int> > divisors(2,std::vector<int> (6,0));

void divide(int & n,int in)
{
	int i=2;
	if(n%i==0)
	{
		n/=i;
		divisors[in][i]++;
		while(n%i==0)
		{
			n/=i;
			divisors[in][i]++;
		}
	}
	for(i=3;i<=5;i+=2)
	{
		if(n%i==0)
		{
			n/=i;
			divisors[in][i]++;
			while(n%i==0)
			{
				n/=i;
				divisors[in][i]++;
			}
		}	
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a,b;
	cin>>a>>b;
	divide(a,0);
	divide(b,1);
	if((a>1 || b>1) && a!=b)
	{
		cout<<-1;
	}
	else
	{
		int ans=0;
		for(int i=0;i<6;i++)
		{
			ans+=abs(divisors[0][i]-divisors[1][i]);
		}
		cout<<ans;
	}
}