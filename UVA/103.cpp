//AC
#include "bits/stdc++.h"
using namespace std;
int nBoxes,dim;
std::vector<vector<int> > boxes;
int dp[31][31];
int taken[31][31];
int vis[31][31];
int curTest=0;

int solve(int indx=0,int maxindx=0)
{
	if(indx==nBoxes)
	{
		return 0;
	}
	if(vis[indx][maxindx]==curTest)
	{
		return dp[indx][maxindx];
	}
	vis[indx][maxindx]=curTest;
	if(maxindx==indx)
	{
		int ans1=solve(indx+1,maxindx+1);
		//take yourself and make it the max
		int ans2=1+solve(indx+1,indx);
		if(ans1>ans2)
		{
			taken[indx][maxindx]=0;
			return dp[indx][maxindx]=ans1;
		}
		else
		{
			taken[indx][maxindx]=1;
			return dp[indx][maxindx]=ans2;
		}
	}

	//check if you can be the new max
	bool ok=1;
	for(int i=0;i<dim;i++)
	{
		if(boxes[indx][i]<=boxes[maxindx][i])
		{
			ok=0;
			break;
		}
	}	

	if(ok)
	{
		int ans1=solve(indx+1,maxindx);
		//take yourself and make it the max
		int ans2=1+solve(indx+1,indx);
		if(ans1>ans2)
		{
			taken[indx][maxindx]=0;
			return dp[indx][maxindx]=ans1;
		}
		else
		{
			taken[indx][maxindx]=1;
			return dp[indx][maxindx]=ans2;
		}	
	}

	taken[indx][maxindx]=0;
	return dp[indx][maxindx]=solve(indx+1,maxindx);

}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(cin>>nBoxes>>dim)
	{
		curTest++;
		boxes=std::vector<std::vector<int> > (nBoxes);
		for(int boxIn=0;boxIn<nBoxes;boxIn++)
		{
			int dimVal;
			for(int d=0;d<dim;d++)
			{
				cin>>dimVal;
				boxes[boxIn].push_back(dimVal);
			}
			sort(boxes[boxIn].begin(), boxes[boxIn].end());
			boxes[boxIn].push_back(boxIn+1);
		}
		sort(boxes.begin(), boxes.end());
		int ans=solve();
		cout<<ans<<endl;
		int curmax=0;
		for(int i=0;i<nBoxes && ans>0;i++)
		{
			if(taken[i][curmax])
			{
				ans--;
				curmax=i;
				cout<<boxes[i][dim];
				if(ans)
					cout<<" ";
			}
			else if(curmax==i)
			{
				curmax++;
			}
		}
		cout<<endl;
	}
}