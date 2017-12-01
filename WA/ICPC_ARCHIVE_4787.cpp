// TLE
#include "bits/stdc++.h"
using namespace std;
#define COL first
#define ROW second

void compress(const std::vector<pair<int,int>> & p, unordered_map<int,int> & r,
				unordered_map<int,int> & c, unordered_map<int,int> & p_r,
				unordered_map<int,int> & p_c)
{
	set<int> unique_r, unique_c;
	for (auto pt : p)
	{
		unique_r.insert(pt.ROW);
		unique_c.insert(pt.COL);
	}
	int idx = 0;
	int last_r = -1;
	for (auto cx: unique_r)
	{
		if (last_r < cx-1)
		{
			p_r[idx] = last_r+1;
			idx++;
		}
		r[cx] = idx++;
		p_r[idx-1]= cx;
		last_r = cx;
	}
	idx = 0;
	int last_c = -1;
	for (auto cy: unique_c)
	{
		if (last_c < cy-1)
		{
			p_c[idx] = last_c+1;
			idx++;
		}
		c[cy] = idx++;
		p_c[idx-1] = cy;
		last_c = cy;
	}
}

std::vector<std::vector<int> > can_reach;
int dr[] = {0,1};
int dc[] = {1,0};
int des_r,des_c;

bool dfs(int r,int c)
{
	if (r==des_r && c== des_c)
		return 1;
	if (r>des_r || r<0 || c>des_c || c<0)
		return 0;
	if (can_reach[r][c] !=-1)
		return can_reach[r][c];
	can_reach[r][c] = 0;
	for (int I=0;I<2;I++)
	{
		if (dfs(r+dr[I],c+dc[I]))
			return can_reach[r][c] =1;
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	// n-1 and m-1
	int n,m,w;
	cin>>n>>m>>w;
	int t = 1;
	while (! (n==0 && m==0 && w==0))
	{
		std::vector<pair<int,int> > pts(2*w);
		for (int i=0; i<2*w; i++)
		{
			cin>> pts[i].COL>>pts[i].ROW;
		}
		pts.push_back({m-1,n-1});
		pts.push_back({0,0});
		unordered_map<int,int> compressed_r, compressed_c;
		unordered_map<int,int> idx_to_r, idx_to_c;
		// std::vector<int> p_r, p_c;
		compress(pts, compressed_r, compressed_c, idx_to_r, idx_to_c);
		des_r= compressed_r[pts[2*w].ROW];
		des_c= compressed_c[pts[2*w].COL];
		can_reach = std::vector<std::vector<int> > (des_r+1, std::vector<int> (des_c+1,-1));
		long long int ans = n*m;
		for (int i=0;i<2*w;i+=2)
		{
			int r = compressed_r[pts[i].ROW];
			// cout<<r<<" "<<endl;
			// int y = compressed_y[pts[i].X];
			ans -= 1+ pts[i+1].COL - pts[i].COL;
			for (int c = compressed_c[pts[i].COL];c<=compressed_c[pts[i+1].COL];c++)
			{
				can_reach[r][c] = 0;
			}
		}
		// for (int r=0;r<des_r+1;r++)
		// {
		// 	for (int c=0;c<des_c+1;c++)
		// 	{
		// 		cout << (is_blocked[r][c]?'X':'.');
		// 	}
		// 	cout<<endl;
		// }
		for (int r=0;r<des_r+1;r++)
		{
			int last_r_idx = -1;
			for (int c=0;c<des_c+1;c++)
			{
				int last_c_idx = -1;
				if (can_reach[r][c] == -1)
				{
					// try solving from here
					dfs(r,c);
				}
				// if can_reach[r][c] == 1
				// find ans
				if (can_reach[r][c])
				{
					long long int dr = (r==0)+idx_to_r[r];
					if (r>0)
						dr -= idx_to_r[r-1];
					// else
					// 	yr--;
					long long int dc = (c==0)+idx_to_c[c];
					if (c>0)
						dc -= idx_to_c[c-1];
					// else
					// 	xr--;
					ans -= (dr * dc);
					// cout<<"OK: "<<r<<" "<<c<<": "<<dr*dc<<endl; //<<" "<<yr<<endl;
				}
			}
		}
		printf("Case %d: %lld\n", t++,ans);
		cin>>n>>m>>w;

	}	
	return 0;
}