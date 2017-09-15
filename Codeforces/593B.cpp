//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	std::vector<pair<long double,long double> > intersections(n);
	int xs,xe;
	scanf("%d%d",&xs,&xe);
	for(int i=0;i<n;i++)
	{
		int slope,intercept;
		scanf("%d%d",&slope,&intercept);
		long double y=(slope);
		y*=xs;
		y+=intercept;
		intersections[i].first=y;
		y=(slope);
		y*=xe;
		y+=intercept;
		intersections[i].second=y;
	}
	sort(intersections.begin(), intersections.end());
	std::vector<long double> minEnd(n);
	minEnd[n-1]=intersections[n-1].second;
	for(int i=n-2;i>=0;i--)
	{
		minEnd[i]=(minEnd[i+1],intersections[i].second);
	}

	for(int i=0;i<n-1;i++)
	{
		if(intersections[i].second>minEnd[i+1])
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

}