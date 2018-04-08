#include "bits/stdc++.h"
using namespace std;
typedef pair<int,long long int> node;

long long int rev(long long int n)
{
	long long int ans=0;
	while(n>0)
	{
		ans=(ans*10)+(n%10);
		n=n/10;
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		// freopen("A-small-out.in","w",stdout);
	#endif
	int T;
	cin>>T;
	long long int N;
	priority_queue<node>q;
	for(int t=1;t<=T;t++)
	{
		map<long long int,bool>mp;
		cin>>N;
		q.push({-1,1});
		mp[1]=1;
		while(!q.empty())
		{
			long long int n=q.top().second;
			int l=q.top().first;
			q.pop();
			// cout<<-l<<" "<<n<<endl;
			if(n==N)
			{
				cout<<"Case #"<<t<<": "<<-l<<endl;
				while(!q.empty())
					q.pop();
				break;
			}
			if(mp.find(n+1)==mp.end())
			{
				q.push({l-1,n+1});
				mp[n+1]=1;
			}
			long long int rn=rev(n);
			if((rn>N && n>N) || n%10==0)
			{
				continue;
			}
			if(mp.find(rn)==mp.end())
			{
				q.push({l-1,rn});
				mp[rn]=1;
			}
		}
		while(!q.empty())
			q.pop();
	}	
}