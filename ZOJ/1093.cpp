//AC
#include "bits/stdc++.h"
using namespace std;
#define X first.first
#define Y first.second
#define Z second
int n;
std::vector<pair<pair<int,int>,int> > boxes;
int t =1;

long long int dp[180][181];
int test[180][181];
long long int solve(int indx =0,int last = 180)
{
	if(indx == 6*n)
		return 0;
	if(test[indx][last] == t)
	{
		return dp[indx][last];
	}
	test[indx][last] = t;	
	if (last ==180)
	{
		long long int ans = solve(indx+1,last);
		return dp[indx][last] = max(ans, boxes[indx].Z+solve(indx+1,indx));
	}
	int xl,yl;
	xl= boxes[last].X;
	yl= boxes[last].Y;

	long long int ans = solve(indx+1,last);
	if (boxes[indx].X< xl && boxes[indx].Y< yl)
	{
		ans = max(ans,boxes[indx].Z+solve(indx+1,indx));
	}

	return dp[indx][last]=ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n;
	while(n !=0)
	{
		boxes = std::vector<pair<pair<int,int>,int> >(6*n);	
		for(int i=0;i<n;i++)
		{
			cin>>boxes[i*6].X>>boxes[i*6].Y>>boxes[i*6].Z;
			int x= boxes[i*6].X;
			int y= boxes[i*6].Y;
			int z= boxes[i*6].Z;
			boxes[6*i+1] = {{y,x},z};
			boxes[6*i+2] = {{x,z},y};
			boxes[6*i+3] = {{z,x},y};
			boxes[6*i+4] = {{z,y},x};
			boxes[6*i+5] = {{y,z},x};
		}
		sort(boxes.rbegin(), boxes.rend());
		printf("Case %d: maximum height = %d\n", t,solve());
		t++;
		cin>>n;
	}	
}