//AC
#include "bits/stdc++.h"
using namespace std;

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
		if(n==2)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			long double area = (max(x1,x2)-min(x1,x2)) * (y1+y2);
			area/=2;
			cout<<fixed<<setprecision(1)<<area<<endl;
			continue;
		}
		std::vector<int> x(n),y(n);
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		// for(int i=0;i<n;i++)
		// 	cout<<x[i]<<" "<<y[i]<<endl;
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		std::vector<int> dx(n-1);
		for(int i=0;i<n-1;i++)
		{
			dx[i] = x[i+1]-x[i];
		}
		priority_queue<int> X;
		X.push(dx[0]);
		X.push(dx[n-2]);
		for(int i=0;i<n-2;i++)
		{
			X.push(dx[i]+dx[i+1]);
		}
		long long int area =0;
		for(int i=n-1;i>=0;i--)
		{
			long long int cur_x = X.top();
			X.pop();
			// cout<<cur_x<<endl;
			area += cur_x*y[i];
		}
		long double ans = area;
		ans *=0.5;
		cout<<fixed<<setprecision(1)<<ans<<endl;
	}	
}