#include "bits/stdc++.h"
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int number_of_prerequests[101]={};
	
	
	int n,m,x,y;
	int T=0;
	cin>>n>>m;
	while(n!=0 && m!=0)
	{
		T++;
		vector<int> output;
		vector<int>adjacent_list[101];
		memset(number_of_prerequests,0,sizeof number_of_prerequests);
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			number_of_prerequests[y]++;
			adjacent_list[x].push_back(y);
		}
		int taken_nodes=0;
		bool change=true;
		int mini_node=1,maxi_node=n;
		while(change)
		{
			change=false;
			for(int i=mini_node;i<=maxi_node;i++)
			{
				if(number_of_prerequests[i]==0)
				{
					if(i==mini_node)
					{
						mini_node++;
					}
					if(i==maxi_node)
					{
						maxi_node--;
					}
					output.push_back(i);
					taken_nodes++;
					change=true;
					number_of_prerequests[i]=-1;
					for(int j=0;j<adjacent_list[i].size();j++)
					{
						number_of_prerequests[adjacent_list[i][j]]--;
					}
					break;
				}
			}
		}

		if(taken_nodes==n)
		{

			if(T>1)cout<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<output[i]<<" ";
			}
		}
		cin>>n>>m;

	}
	





	return 0;
}