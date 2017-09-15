#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>primes,other_numbers;
	bool isprime=true;
	for(int i=2;i<=n;i++)
	{
		isprime=true;
		for(int j=i/2;j>=2;j--)
		{
			if(i%j==0)
			{
				isprime=false;
				break;
				//break;
			}
		}
		if(isprime)primes.push_back(i);
	}	
	for(int power=2;power<=10;power++)
	{
		for(int nu=0;nu<primes.size();nu++)
		{
			if(round(pow(primes[nu],power))>n)
			{
				break;
			}	
			other_numbers.push_back(round(pow(primes[nu],power)));
		}
	}
	cout<<other_numbers.size()+primes.size()<<endl;
	for(int i=0;i<primes.size();i++)
	{
		cout<<primes[i]<<" ";
	}
	for(int i=0;i<other_numbers.size();i++)
	{
		cout<<other_numbers[i]<<" ";
	}
	return 0;
}