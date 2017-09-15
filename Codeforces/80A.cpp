#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	//if(n==2)n=n+1;
	bool isprime=false;
	//cout<<(1&&(n==2))<<endl;
	for(int i=n+1;i<m && !isprime;i++)
	{
		isprime=true;
		for(int j=i/2;j>=2;j--)
		{
			if(i%j==0)
			{
				isprime=false;
				break;
			}
		}
	}
	if(isprime)cout<<"NO";
	else 
	{
		for(int i=2;i<=m/2;i++)
		{
			if(m%i==0)
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<< "YES";
	}
	return 0;
}