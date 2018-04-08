//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		// freopen("in.txt","r",stdin);
		freopen("A-large-practice.in","r",stdin);
		freopen("A-large-practice.out","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,x;
		cin>>n>>x;
		std::vector<int> files(n);
		for(int i=0;i<n;i++)
			cin>>files[i];
		sort(files.begin(), files.end());
		std::vector<bool> done(n,false);
		int cand=0;
		int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			if(done[i])
				break;
			ans++;
			done[i]=true;
			if(cand>=i)
				continue;
			if(files[i]+files[cand]<=x)
			{
				done[cand]=true;
				cand++;
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}