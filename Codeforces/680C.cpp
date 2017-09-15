#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	std::vector<int> primes(105,1);
	for(int i=2;i<=50;i++)
	{
		if(primes[i]==1)
		{
			for(int j=2;i*j<=50;j++)
				primes[i*j]=0;
		}
	}
	int count=0;
	string s;
	for(int i=2;i<=50;i++)
	{
		if(primes[i])
		{
			cout<<i<<endl;
			fflush(stdout);
			cin>>s;
			if(s.find("yes")!=-1)
			{
				count++;
				if(count>=2)
				{
					cout<<"composite"<<endl;
					fflush(stdout);
					return 0;
				}
				else if(i*i<=100)
				{
					cout<<i*i<<endl;
					fflush(stdout);
					cin>>s;
					if(s.find("yes")!=-1)
					{
						cout<<"composite"<<endl;
						fflush(stdout);
						return 0;
					}
				}
			}
		}
	}
	cout<<"prime"<<endl;
	fflush(stdout);
	return 0;
}



















