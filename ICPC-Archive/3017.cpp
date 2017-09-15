//AC
#include "bits/stdc++.h"
using namespace std;
bool notprime[1111112];
std::vector<short> coef;
void generateCoef(int no)
{
	coef.clear();
	while(no>0)
	{
		coef.push_back(no%10);
		no/=10;
	}
	sort(coef.begin(), coef.end());
}
bool isPermPrime(int & no)
{
	generateCoef(no);
	do
	{
		int curVal=0;
		int mul=1;
		for(int i=coef.size()-1;i>=0;i--,mul*=10)
		{
			curVal+=mul*coef[i];
		}
		if(abs(curVal-no)/9<=1111111 && !notprime[abs(curVal-no)/9])
		{
			return 1;
		}
	}
	while(next_permutation(coef.begin(), coef.end()));
	return 0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	notprime[0]=notprime[1]=1;
	for(int i=2;i<=1111111;i++)
	{
		if(!notprime[i])
		{
			for(int mult=2;i*mult<=1111111;mult++)
			{
				notprime[i*mult]=1;
			}
		}
	}
	int t;
	scanf("%d",&t);
	int p,q;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		scanf("%d %d",&p,&q);
		if(p>q)
			swap(p,q);
		for(int val=p;val<=q;val++)
			if(isPermPrime(val))
				ans++;
		printf("Case %d: %d\n",i,ans);
	}
	// cout<<maxPrime<<endl;
}