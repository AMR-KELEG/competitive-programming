//AC
#include "bits/stdc++.h"
#define R first.first
#define I first.second
#define X second.first
#define Y second.second
#define EPS 0.0000000001
using namespace std;

bool in_range(long double d , long double r)
{
	if(d<=r || abs(d-r)<=EPS)
	{	
		return 1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n)
	{
		std::vector< pair< pair<double,int> ,pair<double,double> > > pts(n);
		for(int i=0;i<n;i++)
		{
			cin>>pts[i].R>>pts[i].X>>pts[i].Y;
			pts[i].I = i;
		}
		sort(pts.rbegin(), pts.rend());
		
		std::vector<int> indecies;
		std::vector<int> ans;
		for(int i=0;i<n;i++)
		{
			long double cur_x = pts[i].X;
			long double cur_y = pts[i].Y;
			bool is_inside = 0;
			for(int j=0;j<indecies.size();j++)
			{
				int indx = indecies[j];
				long double x = pts[indx].X;
				long double y = pts[indx].Y;
				long double r = pts[indx].R;
				long double dis = (cur_x-x)*(cur_x-x) + (cur_y-y)*(cur_y-y);
				dis = sqrt(dis);
				if (in_range(dis,r))
				{
					is_inside = 1;
					break;
				}
			}
			if(!is_inside)
			{
				indecies.push_back(i);
				ans.push_back(pts[i].I);
			}
		}
		sort(ans.begin(), ans.end());
		printf("%d\n", int(ans.size()));
		for(int i=0;i<ans.size();i++)
		{
			if(i>0)
				printf(" ");
			printf("%d", ans[i]+1);
		}
		printf("\n");
		cin>>n;
	}	
}