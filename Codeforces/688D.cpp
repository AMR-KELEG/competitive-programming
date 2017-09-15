//AC
#include "bits/stdc++.h"
using namespace std;
bool alreadyComputed[1000001]={};
std::vector<int> primes;
map<int,int>primesCount;
void genPrimes()
{
	std::vector<bool> isprime(1000001,1);
	isprime[0]=isprime[1]=0;
	for(int i=2;i<=1000000;i++)
	{
		if(isprime[i])
		{
			primes.push_back(i);
			for(int m=2;m*i<=1000000;m++)
				isprime[m*i]=0;
		}
	}
}

void factorize(int no)
{
	for(int i=0;i<primes.size() && no>=primes[i] && primes[i]*primes[i]<=no;i++)
	{
		if(no%primes[i]==0)
		{
			int counter=0;
			while(no%primes[i]==0)
			{
				counter++;
				no/=primes[i];
			}
			primesCount[primes[i]]=counter;
		}
	}
	if(no>1)
		primesCount[no]=1;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	scanf("%d%d",&n,&k);
	genPrimes();
	factorize(k);
	int no;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&no);
		if(!alreadyComputed[no] && no!=1)
		{
			alreadyComputed[no]=1;
			for(int i=0;i<primes.size() && no>=primes[i] && primes[i]*primes[i]<=no;i++)
			{
				if(no%primes[i]==0)
				{
					int counter=0;
					while(no%primes[i]==0)
					{
						counter++;
						no/=primes[i];
					}
					if(counter>=primesCount[primes[i]])
					{
						primesCount[primes[i]]=0;
					}
				}
			}
			if(no>1 && primesCount[no]==1)
			{
				primesCount[no]=0;
			}
		}
	}	
	for(auto p:primesCount)
	{
		if(p.second!=0)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}