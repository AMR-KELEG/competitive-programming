//AC
#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000000000LL
int N,H,W;
#define polygon pair<pair<int,int>,pair<int,int>>
#define X1 second.first
#define X2 second.second
#define Y1 first.first
#define Y2 first.second
std::vector<polygon> rectangles;

void add_pol(int h, int w, int d, int is_right, int & i)
{
	int y1 = min(H, d);
	int y2 = min(H, d+h);

	int x1,x2;
	if(is_right)
	{
		x1 = max(0, W-w);
		x2 = W;
	}
	else
	{
		x1 = 0;
		x2 = min(w, W);
	}
	rectangles [i] = {{y1,y2}, {x1,x2}};
}

long double dp[101][101];
int vis[101][101];
int t;

long double dis(pair<int,int> & p1, pair<int,int> & p2)
{
	long long int dx = p1.first-p2.first;
	long long int dy = p1.second-p2.second;
	dx *= dx;
	dy *= dy;
	return sqrt(dx+dy);
}

long double find_dis(int i1, int i2)
{
	polygon p1 = rectangles[i1];
	polygon p2 = rectangles[i2];
	if (p1.X1 == p2.X1 || p1.X2 == p2.X2)
		return max(0, max(p1.Y1, p2.Y1) - min(p1.Y2,p2.Y2));
	if(p1.X1 !=0)
		swap(p1,p2);
	if(p1.X2 >=p2.X1 && p1.X2 <=p2.X2)
		return max(0, max(p1.Y1, p2.Y1) - min(p1.Y2,p2.Y2));
	int yhigh = max(p1.Y1,p2.Y1);
	if (yhigh>=p1.Y1 && yhigh<=p1.Y2 && yhigh>=p2.Y1 && yhigh<=p2.Y2)
	{
		return max(0, max(p1.X1,p2.X1)-min(p1.X2,p2.X2));
	}
	int X[]={p1.X1,p1.X2};
	int Y[]={p1.Y1,p1.Y2}; 
	std::vector<pair<int,int>> pts1, pts2;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			pts1.push_back({X[i],Y[j]});
	}
	X[0]=p2.X1;
	X[1]=p2.X2;
	Y[0]=p2.Y1;
	Y[1]=p2.Y2;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			pts2.push_back({X[i],Y[j]});
	}
	long double ans = dis(pts1[0], pts2[0]);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			ans = min(ans, dis(pts1[i], pts2[j]));
	}
	return max((long double)0.0, ans);
}

long double solve(int cur =0,int next =1)
{
	if (cur == N || next == N+1)
		return max(0, H - rectangles[cur].Y2);
	if (rectangles[cur].Y2 >= H)
		return 0;
	if (vis[cur][next] ==t)
		return dp[cur][next];
	vis[cur][next] = t;
	long double ans = H - rectangles[cur].Y2;
	ans = min(ans, solve(cur,next+1));
	ans = min(ans, find_dis(cur,next) + solve(next,next+1));
	return dp[cur][next] = ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	#ifdef ONLINE_JUDGE
		freopen("street.in","r",stdin);
	#endif

	int T;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>N>>H>>W;
		rectangles = std::vector<polygon> (N+1);
		rectangles[0] = {{0,0}, {0,W}};
		for(int i=1;i<=N;i++)
		{
			int h,w,d,is_right;
			cin>>h>>w>>d>>is_right;
			add_pol(h,w,d,is_right,i);
		}
		sort(rectangles.begin(), rectangles.end());
		// cout<<"Rectangles"<<endl;
		// for(int i=0;i<rectangles.size();i++)
		// {
		// 	cout<<"(Y,X): "<<rectangles[i].Y1<<" "<<rectangles[i].Y2<<" "
		// 		<<rectangles[i].X1<<" "<<rectangles[i].X2<<endl;
		// }
		cout<<fixed<<setprecision(6)<<solve()<<endl;
		// cout<<endl;
	}	
}