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
	string s;
	cin>>s;
	deque<char>q;
	bool insertLeft=0;
	if(s.size()%2==0)
		insertLeft=1;
	for(int i=0;i<s.size();i++)
	{
		if(insertLeft)
		{
			q.push_front(s[i]);
		}
		else
		{
			q.push_back(s[i]);
		}
		insertLeft=!insertLeft;
	}
	for(int i=0;i<s.size();i++)
	{
		cout<<q.front();
		q.pop_front();
	}
}