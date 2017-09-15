#include "bits/stdc++.h"
using namespace std;
typedef pair< deque<char>,pair<int,int> > sub;
int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	int k;
	cin>>k;
	int n=s.size();
	if(2*k>(n*(n+1)))
		cout<<"No such line.";
	else
	{
		k--;
		priority_queue<sub,std::vector<sub> ,greater<sub> >q;
		deque<char>dq;
		for(int i=0;i<s.size();i++)
		{
			dq.push_back(s[i]);
			q.push(pair< deque<char>,pair<int,int> >(dq,pair<int,int>(i,i)));
			dq.pop_front();
		}
		while(!q.empty() && k>0)
		{
			int st=q.top().second.first;
			int en=q.top().second.second;
			dq=q.top().first;
			q.pop();
			k--;
			if(en+1<s.size())
			{
				en++;
				dq.push_back(s[en]);
				q.push(pair< deque<char>,pair<int,int> >(dq,pair<int,int>(st,en)));
			}
		}
		// cout<<k<<endl;
		if(q.empty())
		{
			cout<<"No such line.";
		}
		else
		{
			dq=q.top().first;
			while(!dq.empty())
			{
				printf("%c", dq.front());
				dq.pop_front();
			}
		}

		
	}

}