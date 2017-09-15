//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,t;
	cin>>n>>t;
	std::vector<double> v(10*n,0);
	while(t--)
	{
		v[1]++;
		for(int i=1;i<=n;i++)
		{
			int offset=(i*(i-1))/2;
			for(int node=1;node<=i;node++)
			{
				if(v[node+offset]>1)
				{
					v[node+offset+i]+=(v[node+offset]-1)*0.5;
					v[node+i+1+offset]+=(v[node+offset]-1)*0.5;
					// cout<<"Aff "<<node+i+offset<<" "<<node+i+1+offset<<endl;
					v[node+offset]=1;
				}
				// cout<<v[node+offset]<<" ";
			}
			// cout<<endl;
		}
		// cout<<endl<<endl;
	}

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int offset=(i*(i-1))/2;
		for(int node=1;node<=i;node++)
		{
			if(abs(v[node+offset]-1)<0.0000001)
			{
				ans++;
				// cout<<v[node+offset]<<" has "<<i<<" "<<node<<endl;
			}
		}
	}
	cout<<ans;
}