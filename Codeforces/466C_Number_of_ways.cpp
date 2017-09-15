#include "bits/stdc++.h"
using namespace std;
int main()
{
	long long int n,ai,totalsum=0;
	map<long long int,long long int>rep;//sum - count
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ai;
		totalsum+=ai;
		rep[totalsum]++;
	}
	if(totalsum==0)
	{
		if(rep.find(0)!=rep.end())
		{
			if(rep[0]>=3)
			{
				cout.setf(ios::fixed);
				cout << setprecision(0) << (0.5*rep[0]*rep[0])+(-1.5*rep[0])+(1);
			}
			else
			{
				cout<<0;
			}
		}
		else //redundant
		{
			cout<<0;
		}
	}
	else if(totalsum%3==0)
	{
		if(rep.find(totalsum/3)!=rep.end() && rep.find(2*totalsum/3)!=rep.end())
		{
			cout.setf(ios::fixed);
			cout << setprecision(0) << rep[totalsum/3]*rep[2*totalsum/3];
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}