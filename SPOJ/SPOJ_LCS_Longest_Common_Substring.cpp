#include "bits/stdc++.h"
using namespace std;
vector <vector<int> >dp;
//int dp[250000][250000]={};
string s1,s2;
int lcs(int p,int q)
{
	//cout<<p<<" "<<q<<endl;
	if(p<0 || q<0)return 0;
	if(dp[p][q]!=-1)return dp[p][q];
	if(s1[p]==s2[q])return dp[p][q]=1+lcs(p-1,q-1);
	return dp[p][q]=0;
}

int main()
{	
	//s1="alsdfkjfjkdsal",s2="fdjskalajfkdsla";
	s1="besbesa";s2="besabes";
	//memset(dp,sizeof dp,-1);
	dp.assign(250000,vector<int>(250000,-1)); //size,value
	cout<<dp[0][0]<<endl;
	//cin>>s1>>s2;
	//dp.assign(s1.size(),vector<int>(s2.size(),-1)); //size,value
	int max_length=0;
	/*
	for(int p=s1.size()-1;p>=0;p--)
	{
		for(int q=s2.size()-1;q>=0;q--)
			max_length=max(max_length,lcs(p,q));
	}
	*/
	cout<<max_length<<endl;
	return 0;
}