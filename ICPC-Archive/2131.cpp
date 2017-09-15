//AC
#include "bits/stdc++.h"
#define PI (2*acos(0))
using namespace std;
int n,m;
int t=1;

std::vector<long double> angles;
std::vector<long double> x;
std::vector<long double> y;
long double dp[40][80][40]; // start cur remaining_vertices
int vis[40][80][40];

long double area(int fi,int se,int th)
{
	long double ans = 0.5 * ((x[fi]+x[se])*(y[fi]-y[se]) + (x[se]+x[th])*(y[se]-y[th]) + (x[th]+x[fi])*(y[th]-y[fi]));
	// cout<<"Area for "<<fi<<" "<<se<<" "<<th<<" "<<abs(ans)<<endl;
	return abs(ans);
}

long double find_max_area(int start_indx, int cur_indx, int rem_vert)
{
	if (cur_indx == n+start_indx)
		return 0;
	if (rem_vert == 0)
		return 0;
	if (vis[start_indx][cur_indx][rem_vert] == t)
		return dp[start_indx][cur_indx][rem_vert];
	vis[start_indx][cur_indx][rem_vert] = t;
	// start cur next
	long double ans =0;
	for (int next_indx = cur_indx+1;next_indx<start_indx+n;next_indx++)
	{
		ans = max(ans,find_max_area(start_indx, next_indx, rem_vert-1)+area(start_indx,cur_indx,next_indx));
	}
	return dp[start_indx][cur_indx][rem_vert]=ans;
}

long double solve()
{
	long double ans =0;
	for (int i=0;i<n;i++)
	{
		for (int next_indx = i+1;next_indx<n+i;next_indx++)
		{
			ans = max(ans,find_max_area(i,next_indx,m-2));
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	cin>>n>>m;
	while(n>0)
	{
		angles = std::vector<long double> (n);
		x = std::vector<long double> (n);
		y = std::vector<long double> (n);
		for (int i=0;i<n;i++)
		{
			cin>>angles[i];
		}
		sort (angles.begin(), angles.end());
		for (int i=0;i<n;i++)
		{
			x[i] = cos(angles[i]*2*PI);
			y[i] = sin(angles[i]*2*PI);
			x.push_back(x[i]);
			y.push_back(y[i]);
			// cout<<fixed<<"Point "<<x[i]<<" "<<y[i]<<endl;
		}
		cout<<fixed<<setprecision(6)<<solve()<<"\n";
		t++;
		cin>>n>>m;
	}	
}