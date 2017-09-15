#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	double x0,y0;
	cin>>n>>x0>>y0;
	set<double>slopes;
	double slope;
	bool ver=false;
	double x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		if(abs(x-x0)<=0.000001)ver=1;
		else
		{
			slope=(y-y0)/(x-x0);
			//cout<<slope<<endl;
			slopes.insert(slope);
		}
	}
	cout<<ver+slopes.size();
	return 0;
}