//AC
#include "bits/stdc++.h"
#define Point pair<int,int>
#define X first
#define Y second

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,w,h;
	cin>>n>>w>>h;
	std::vector<Point> pts(n);
	for(int i=0;i<n;i++)
		cin>>pts[i].X>>pts[i].Y;	
	pts.push_back({0,0});
	pts.push_back({w,h});

	sort (pts.begin(), pts.end());
	// sorted by x then by y
	// cout<<pts.size()<<endl;
	int side = 0;
	int x_ans = 0, y_ans=0;
	for (int i=0;i<pts.size();i++)
	{
		for(int j=i+1;j<pts.size();j++)
		{
			int min_x = pts[i].X;
			int max_x = pts[j].X;
			if (min_x==max_x)
				continue;
			priority_queue<int> y;
			// cout<<min_x<<" "<<max_x<<endl;
			y.push(0);
			for (int k=0;k<pts.size();k++)
			{
				if (pts[k].X>min_x && pts[k].X< max_x)
				{
					y.push(pts[k].Y);
				}  
			}
			int cur_y = h;
			while(!y.empty())
			{
				int side_len = min (max_x - min_x, cur_y - y.top());
				if (side_len > side)
				{
					side = side_len;
					x_ans = min_x;
					y_ans = y.top();
					// cout<<min_x<<" "<<max_x<<" "<<side_len<<endl;
				}
				cur_y = y.top();
				y.pop();
			}
		}
	}
	cout<<x_ans<<" "<<y_ans<<" "<<side;
}