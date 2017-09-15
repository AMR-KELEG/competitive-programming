#include "bits/stdc++.h"
using namespace std;
int packet_price[1005];
int dp[1005][1005][105]={};//kilos,packets_taken
//vector <vector <vector<int> > >dp;
int min_money(int rem_kilo,int rem_packets,int index_to_take)
{
	//if(index_to_take==1)cout<<"Taking the zero"<<endl;
	if(rem_packets==0 && rem_kilo>0)return 100001;
	if(rem_kilo<0)return 100001;
	if(rem_packets>=0 && rem_kilo==0)return 0;
	if(rem_packets<=0)return 100001;
	if(index_to_take<1)return 100001;
	if(dp[rem_kilo][index_to_take][rem_packets]!=-1)return dp[rem_kilo][index_to_take][rem_packets];
	if(packet_price[rem_kilo]!=-1)
	return dp[rem_kilo][index_to_take][rem_packets]=min( packet_price[index_to_take] + min_money( rem_kilo-index_to_take , rem_packets-1 , min(index_to_take-1,rem_kilo-index_to_take))
		,min_money(rem_kilo,rem_packets,index_to_take-1));
	
	return	dp[rem_kilo][index_to_take][rem_packets]=min_money(rem_kilo,rem_packets,index_to_take-1);
}


int main()
{
	/*
	freopen("out.txt","w",stdout);
	cout<<"1"<<endl<<"100 100"<<endl;
	for(int i=0;i<99;i++)cout<<i<<" ";
		cout<<100;
	*/
	freopen("in.txt","r",stdin);
	int c;
	ios::sync_with_stdio(false);
	cin>>c;
	int n,k;
	//vector <vector <vector<int> > >temp(5,vector<int>(5,vector<int>(5,-1)));
	while(c--)
	{
		cin>>n>>k;
		//dp.assign(k+5, vector<int> (k+5, `vector<int> (n+5,-1)));
		memset(dp,-1,sizeof dp);
		packet_price[0]=-1;
		for(int i=0;i<k;i++)
		{
			cin>>packet_price[i+1];
		}
		//int m=1;
		int m=min_money(k,n,k);
		if(m>100000)cout<<"-1"<<endl;
		else cout<<m<<endl;
	}
	/*
	*/
	return 0;
}