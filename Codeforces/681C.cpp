//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	// std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	priority_queue<int,std::vector<int> ,greater<int> >q;
	string s;
	int x;
	queue<char> outq;
	queue<int> val;
	while(n--)
	{
		cin>>s;
		if(s=="removeMin")
		{
			if(q.empty())
			{
				// insert any value
				outq.push('i');
				val.push(0);
				outq.push('r');
			}
			else
			{
				// remove min=2 insert a value to be removed
				outq.push('r');
				q.pop();
			}
		}
		// 
		else
		{
			scanf("%d",&x);
			if(s=="getMin")
			{
				while(!q.empty() && q.top()<x)
				{
					outq.push('r');
					q.pop();
				}
				//if top> min -> insert x
				if(q.empty() || q.top()>x)
				{
					outq.push('i');
					val.push(x);
					q.push(x);
				}
				outq.push('g');
				val.push(x);
			}
			else
			{
				//insert 
				outq.push('i');
				val.push(x);
				q.push(x);
			}
		}
	}


	printf("%d\n", (int)outq.size());
	while(!outq.empty())
	{
		char c=outq.front();
		if(c=='r')
		{
			printf("removeMin\n");
			// val.pop();
		}
		else if(c=='i')
		{
			printf("insert %d\n", val.front());
			val.pop();
		}
		else
		{
			printf("getMin %d\n", val.front());
			val.pop();
		}
		outq.pop();
	}
}	