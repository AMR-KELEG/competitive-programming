//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int heros,towers,damage,health;
	priority_queue<int> q;
	bool can; 
	while(t--)
	{
		can=1;
		cin>>heros>>towers>>damage;
		for(int i=0;i<heros;i++)
		{
			cin>>health;
			q.push(health);
		}
		for(int i=0;i<towers;i++)
		{
			health=q.top()-damage;
			q.pop();
			if(health<=0)
			{
				can=0;
				while(!q.empty())
					q.pop();
				break;
			}
			else
			{
				q.push(health);
			}
		}
		if(can)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		while(!q.empty())
			q.pop();
	}	
}