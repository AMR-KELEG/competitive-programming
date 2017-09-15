#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;
string s;
string t;
long long int dp[100001];
long long int solve(int i)
{
	if(dp[i]!=-1)
		return dp[i];
	long long int ans=0;
	int st=i;
	bool done=0;
	while(!done && st<s.size())
	{
		done=1;
		int in;
		for(in=0;in<t.size() && st+in<s.size();in++)
			if(s[st+in]!=t[in])
			{
				break;
			}
		if(in!=t.size())
		{	
			st++;
			done=0;
		}
	}
	if(done)
	{
		cout<<"Index : "<<i<<" "<<st+t.size()<<" "<<endl;
		ans=1;
	}
	for(int in=st+t.size();in<s.size();in++)
	{
		ans+=1+solve(in);
		ans%=MOD;
	}
	return dp[i]=ans%MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// O(n*n) algorithm
	cin>>s>>t;
	memset(dp,-1,sizeof dp);
	long long int ans=0;
	for(int i=0;i<s.size();i++)
	{
		ans+=solve(i);
		ans%=MOD;
	}
	cout<<ans;

}	