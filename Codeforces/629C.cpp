#include "bits/stdc++.h"
using namespace std;
long long int counter=0;
int n,m;
int reqpre=0,reqsuf=0;
int maxop,maxcl;
long long int dp[2005][2005];
long long int solve(int op,int cl)
{

	if(op==maxop)
		return 1;
	if(dp[op][cl]!=-1)
		return dp[op][cl];
	long long int ans=0;
	if(op<maxop)
		ans+=solve(op+1,cl);
	if(cl<maxcl)
		ans+=solve(op,cl+1);
	cout<<ans<<endl;
	return dp[op][cl]=ans;
}
void nextpre(int op,int cl)
{
	cout<<op<<" "<<cl<<endl;
	if(op-cl==reqpre)
	{
		counter+=solve(op,cl);
		if(op<maxop && cl<maxcl)
			nextpre(op+1,cl+1);
	}
	if(op<maxop)
		nextpre(op+1,cl);
	if(cl<maxcl && op>cl && op<maxop)
		nextpre(op,cl+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	memset(dp,-1,sizeof dp);
	cin>>n>>m;//add = n-m
	string s;
	cin>>s;
	stack<char>st;
	for(int i=0;i<m;i++)
	{
		if(!st.empty())
		{
			if(st.top()!=s[i])
				st.pop();
			else
				st.push(s[i]);
		}
		else
		{
			st.push(s[i]);
		}
	}
	char c;
	while(!st.empty())
	{
		c=st.top();
		st.pop();
		if(c==')')
			reqpre++;
		else
			reqsuf++;
	}
	maxop=reqpre+ (n-m-(reqsuf+reqpre))/2;
	maxcl=reqsuf+ (n-m-(reqsuf+reqpre))/2;
	//cout<<"Max "<<maxop<<" "<<maxcl<<endl;
	//cout<<"Req "<<reqpre<<" "<<reqsuf<<endl;
	if(n-m-(reqpre+reqsuf) <0 || ( n-m-(reqpre+reqsuf) )%2)
		cout<<0;
	else
	{
		nextpre(0,0);
		cout<<counter<<endl;
	}
}