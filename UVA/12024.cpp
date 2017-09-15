//AC
#include "bits/stdc++.h"
using namespace std;
int fact[13]={};
int n;

void prepare(int i=0)
{
	if(i==13)
		return;
	if(i==0)
	{
		fact[i]=1;
	}
	else
	{
		fact[i]=i*fact[i-1];
	}
	prepare(i+1);
}

short count_ones(int val)
{
	short ones=0;
	while(val>0)
	{
		ones+=(val&1);
		val=(val>>1);
	}
	return ones;
}


int main()
{
	freopen("in.txt","r",stdin);
	prepare();
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int num=0,den=fact[n];
		for(int mask=0;mask<(1<<n);mask++)
		{
			short ones=count_ones(mask);
			int val=fact[n-ones];
			if(ones%2)
			{
				//Odd sub
				num-=val;
			}
			else
			{
				//even add
				num+=val;
			}
		}
		cout<<num<<"/"<<den<<endl;
	}

}