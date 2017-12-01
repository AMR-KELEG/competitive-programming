/* AC
Generate Tree and greedily choose areas to add or subtract.
*/
#include "bits/stdc++.h"
using namespace std;
#define Point complex<long double>
#define X real()
#define Y imag()
#define EPS 1e-9
#define INF 1000000000
const long double PI = 2*acos(0);

std::vector<Point> pts;
std::vector<long double> rad;

bool is_inside(int small, int large)
{
	long double dis = abs(pts[small] - pts[large]);
	dis += rad[small];
	return dis<rad[large] || (abs(dis-rad[large])<=EPS);
}

std::vector<bool> has_par;
std::vector<std::vector<int> > adjList;

long double dfs(int indx, int d=0)
{
	long double ans = 0;
	long double cur_area = PI * rad[indx] * rad[indx];
	if (d<2)
	{
		ans += cur_area;
	}
	else if (d%2)
	{
		ans += cur_area;
	}
	else
	{
		ans -= cur_area;
	}

	for (auto ch:adjList[indx])
	{
		ans+= dfs(ch, d+1);
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d", &n);
	pts = std::vector<Point> (n);
	rad = std::vector<long double> (n);	
	for (int i=0;i<n;i++)
	{
		long double x,y,r;
		scanf("%LF %LF %LF", &x, &y, &r);
		pts[i] = Point(x,y);
		rad[i] = r;
	}
	has_par = std::vector<bool> (n, 0);
	adjList = std::vector<std::vector<int> > (n);
	// Find parent of each node
	for (int i=0;i<n;i++)
	{
		int min_radius = INF;
		int cur_par = -1;
		for (int j=0;j<n;j++)
		{
			if (i==j)
				continue;
			if (is_inside(i,j) && rad[j]<min_radius)
			{
				min_radius = rad[j];
				cur_par = j;
			}
		}
		if (cur_par !=-1)
		{
			has_par[i] =1;
			adjList[cur_par].push_back(i);
			// cout<<i+1<<" has parent "<<cur_par+1<<endl;
		}
		// else
		// {
		// 	cout<<i+1<<" has no parent"<<endl;
		// }
	}
	long double ans = 0;
	for (int i=0;i<n;i++)
	{
		if (!has_par[i])
		{
			ans += dfs(i);
		}
	}
	printf("%0.10LF\n", ans);
}	