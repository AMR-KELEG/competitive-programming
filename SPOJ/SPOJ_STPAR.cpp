//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	while(n!=0)
	{	
		queue<int>q;
		int t;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			q.push(t);
		}
		int next=1;
		stack<int>s;
		bool ok=1;
		while(!q.empty())
		{
			if(q.front()==next)
			{
				q.pop();
				next++;
			}
			else if(!s.empty())
			{
				if(s.top()==next)
				{
					s.pop();
					next++;
				}
				else
				{
					if(q.front()>s.top())
					{
						ok=0;
						break;
					}
					else
					{
						s.push(q.front());
						q.pop();
					}
				}
			}
			else
			{
				s.push(q.front());
				q.pop();
			}
		}

		if(ok)
			cout<<"yes\n";
		else
			cout<<"no\n";
		cin>>n;
	}
	
}