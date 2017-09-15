//AC
#include "bits/stdc++.h"
using namespace std;

string A,B;
long long int dp[32][2][2];
long long int dpCount[32][2][2];

void appendZeros(string & s)
{
	s=string(32-(int)s.size(),'0')+s;
}

long long int findcount(int in=0,bool largerthanA=0,bool smallerthanB=0)
{
	if(in==32)
		return 1;
	if(dpCount[in][largerthanA][smallerthanB]!=-1)
		return dpCount[in][largerthanA][smallerthanB];
	
	long long int ans=0;
	int minv=0,maxv=9;
	if(largerthanA)
	{
		//take all from 0 to value that make it smallerthanB
		if(!smallerthanB)
		{
			maxv=B[in]-'0';
		}
	}
	else if(smallerthanB)
	{
		// min value 
		if(!largerthanA)
		{
			minv=A[in]-'0';
		}
	}
	else
	{
		// both are 0
		maxv=B[in]-'0';
		minv=A[in]-'0';
	}
	// cout<<"IN "<<in<<endl;
	for(int i=minv;i<=maxv;i++)
		ans+=findcount(in+1,largerthanA || (i>A[in]-'0'),smallerthanB || (i<B[in]-'0'));
	return dpCount[in][largerthanA][smallerthanB]=ans;
}

long long int solve(int in=0,bool largerthanA=0,bool smallerthanB=0)
{
	if(in==32)
		return 0;
	if(dp[in][largerthanA][smallerthanB]!=-1)
		return dp[in][largerthanA][smallerthanB];
	long long ans=0;
	// cout<<in<<endl;
	int minv=0,maxv=9;
	if(largerthanA)
	{
		//take all from 0 to value that make it smallerthanB
		if(!smallerthanB)
		{
			maxv=B[in]-'0';
		}
	}
	else if(smallerthanB)
	{
		// min value 
		if(!largerthanA)
		{
			minv=A[in]-'0';
		}
	}
	else
	{
		// both are 0
		maxv=B[in]-'0';
		minv=A[in]-'0';
	}

	// cout<<in<<" "<<minv<<" "<<maxv<<endl;
	for(int i=minv;i<=maxv;i++)
	{
		ans+=(i*findcount(in+1,largerthanA || (i>A[in]-'0'),smallerthanB || (i<B[in]-'0')));
		ans+=solve(in+1,largerthanA || (i>A[in]-'0'),smallerthanB || (i<B[in]-'0'));
	}
	return dp[in][largerthanA][smallerthanB]=ans;
}

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	cin>>A>>B;
	while(A!="-1" && B!="-1")
	{
		appendZeros(A);
		appendZeros(B);
		memset(dp,-1,sizeof dp);
		memset(dpCount,-1,sizeof dpCount);
		cout<<solve()<<endl;
		cin>>A>>B;
	}

}