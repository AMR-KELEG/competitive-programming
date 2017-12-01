// AC
#include "bits/stdc++.h"
using namespace std;
#define Rectangle pair<pair<int,int>, pair<int,int> >
#define xmin first.first
#define ymin first.second
#define xmax second.first
#define ymax second.second

std::vector<Rectangle> rects;
std::vector<std::vector<int>> grid;
int R,C;

void find_mapping (map<int,int> & x_to_indx, map<int,int> & y_to_indx,
				   map<int,int> & indx_to_x, map<int,int> & indx_to_y)
{
	set<int> unique_x;
	set<int> unique_y;
	for (auto rect: rects)
	{
		unique_x.insert(rect.xmin);
		unique_x.insert(rect.xmax);
		unique_y.insert(rect.ymin);
		unique_y.insert(rect.ymax);
	}
	int idx = 0;
	for (auto x:unique_x)
	{
		indx_to_x[idx] = x;
		x_to_indx[x] = idx++;
	}
	idx = 0;
	for (auto y:unique_y)
	{
		indx_to_y[idx] = y;
		y_to_indx[y] = idx++;
	}
}
std::vector<vector<bool> > vis;
int dr[]= {0,0,1,-1};
int dc[]= {1,-1,0,0};
void dfs(int r,int c)
{
	if (r<0 || r==R || c==C || c<0)
		return ;
	if (vis[r][c])
		return ;
	if (!grid[r][c])
		return ;
	grid[r][c] = 2;
	vis[r][c] = 1;
	for (int i=0;i<4;i++)
		dfs(r+dr[i], c+dc[i]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		rects = std::vector<Rectangle> (n);
		for (int i=0;i<n;i++)
			cin>>rects[i].xmin>>rects[i].ymin>>rects[i].xmax>>rects[i].ymax;
		map<int,int> x_to_indx;
		map<int,int> y_to_indx;
		map<int,int> indx_to_x;
		map<int,int> indx_to_y;
		find_mapping(x_to_indx, y_to_indx, indx_to_x, indx_to_y);
		R = x_to_indx.size();
		C = y_to_indx.size();
		grid = std::vector<std::vector<int> > (x_to_indx.size(), std::vector<int> (y_to_indx.size(),0));
		vis = std::vector<std::vector<bool> > (x_to_indx.size(), std::vector<bool> (y_to_indx.size(),0));
		for (auto r: rects)
		{
			int mapped_x = x_to_indx[r.xmin];
			int mapped_y = y_to_indx[r.ymin];
			int end_x = x_to_indx[r.xmax];
			int end_y = y_to_indx[r.ymax];
			for (int x = mapped_x; x< end_x; x++)
			{
				for (int y = mapped_y; y<end_y; y++)
				{
					grid[x][y] = 1;
				}
			}
		}
		dfs(x_to_indx[rects[0].xmin], y_to_indx[rects[0].ymin]);
		long long int ans = 0;
		for (int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if (grid[i][j] == 2)
				{
					// find mapping of i and i+1
					long long int X = indx_to_x[i];
					long long int Y = indx_to_x[i+1];
					// find mapping o j and j+1
					long long int Z = indx_to_y[j];
					long long int L = indx_to_y[j+1];
					ans += (Y-X) * (L-Z);
				}
			}
		}
		cout<<ans<<'\n';
		if (T)
			cout<<'\n';
	}	
}