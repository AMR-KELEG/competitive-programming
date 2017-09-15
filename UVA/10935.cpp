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
		deque<int>s;
		for(int i=n;i>0;i--)
		{
			s.push_front(i);
		}
		queue<int>q;
		while(s.size()>1)
		{
			q.push(s.front());
			s.pop_front();
			int t=s.front();
			s.pop_front();
			s.push_back(t);
		}
		cout<<"Discarded cards:";
		while(q.size()>1)
		{
			cout<<" "<<q.front()<<",";
			q.pop();
		}
		if(q.size()==1)
		{
			cout<<" "<<q.front();
		}
		cout<<"\nRemaining card: "<<s.front()<<endl;
		

		cin>>n;
	}	
}