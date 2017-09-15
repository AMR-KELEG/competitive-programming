#include "bits/stdc++.h"
using namespace std;
int main()
{
	long long int primes[]={2,3,5,7,11,13,17,19,23,29,31,37};
	set<long long int>lucky_numbers,threeprimes;
	long long int num;
	for(int i=0;i<9;i++)
	{
		for(int j=i;j<10;j++)
		{
			for(int k=j;k<11;k++)
			{
				if(i!=k && i!=j && j!=k)
				{
					num=primes[i]*primes[j]*primes[k];
					threeprimes.insert(num);
				}
			}
		}
	}
	cout<<threeprimes.size()<<endl;
	num=30;

	/*
	while(lucky_numbers.size()<1000)
	{
		for(int i=0;i<threeprimes.size();i++)
		{
			if(num>threeprimes[i])
				break;
			if (num%threeprimes[i]==0)
			{
				lucky_numbers.insert(num);
				cout<<num<<endl;
				break;
			}
		}
		num++;
	}*/


	int T,n;
/*
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<lucky_numbers[n-1]<<endl;
	}	*/
	return 0;
}