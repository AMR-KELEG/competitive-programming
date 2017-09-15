//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-large-practice.in","r",stdin);
		freopen("A-large-out.in","w",stdout);
	#endif
	int T;
	cin>>T;

	for(int t=1;t<=T;t++)
	{
		int n;
		cin>>n;
		std::vector<int> c(n);
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
		}
		int s1=0;
		int maxd=0;
		for(int i=1;i<n;i++)
		{
			if(c[i]<c[i-1])
			{
				s1+=c[i-1]-c[i];
			}
			maxd=max(maxd,c[i-1]-c[i]);
		}
		//for all try taking min of and availabe this value
		int s2=0;
		for(int i=0;i<n-1;i++)
		{
			s2+=min(c[i],maxd);
		}
		cout<<"Case #"<<t<<": "<<s1<<" "<<s2<<endl;
	}

	
}