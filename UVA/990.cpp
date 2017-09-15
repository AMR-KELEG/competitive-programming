//AC
#include "bits/stdc++.h"
using namespace std;

int depth[35],value[35];
std::vector<std::vector<std::vector<int> > > taken_treasures ;
int dp[35][1005];
int w,n;
int solve(int i,int t)
{
	if(i>n)
	{
		taken_treasures[i][t].clear();
		return 0;
	}
	if(dp[i][t]!=-1)
		return dp[i][t];
	if(t<(depth[i]*3*w))
	{
		//cout<<"Can't dive "<<i<<" "<<t<<endl;
		int ans=solve(i+1,t);
		taken_treasures[i][t]=taken_treasures[i+1][t];
		//cout<<taken_treasures[i][t].size()<<endl;
		return dp[i][t]=ans;
	}
	int a2=value[i]+solve(i+1,t-(depth[i]*3*w));
	int a1=solve(i+1,t);
	if(a1>a2)
	{
		//cout<<"Ignore "<<i<<" "<<t<<endl;
		taken_treasures[i][t]=taken_treasures[i+1][t];
		//cout<<taken_treasures[i][t].size()<<endl;
		return dp[i][t]=a1;
	}
	//cout<<"Take "<<i<<" "<<t<<endl;
	taken_treasures[i][t]=taken_treasures[i+1][t-(depth[i]*3*w)];
	taken_treasures[i][t].insert(taken_treasures[i][t].begin(),i);
	//cout<<taken_treasures[i][t].size()<<endl;
	return dp[i][t]=a2;	
	

}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("o.txt","w",stdout);
	#endif
	int t;
	int d,v;
	bool f=1;
	while(cin>>t>>w)
	{
		if(!f)
			cout<<endl;
		if(f)
			f=0;
		cin>>n;

		for(int i=1;i<=n;i++)
		{
			cin>>depth[i]>>value[i];
		}
		taken_treasures=vector<std::vector<std::vector<int> > > (n+5,std::vector<std::vector<int> >(t+5,std::vector<int> ()));
		memset(dp,-1,sizeof dp);
		cout<<solve(1,t)<<endl;
		cout<<taken_treasures[1][t].size()<<endl;
		for(int i=0;i<taken_treasures[1][t].size();i++)
		{
			cout<<depth[taken_treasures[1][t][i]]<<" "<<value[taken_treasures[1][t][i]]<<endl;
		}
	}	
}