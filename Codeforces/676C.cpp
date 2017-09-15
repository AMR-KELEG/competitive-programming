//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); 
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n,k;
	cin>>n>>k;
	string s;
	int maxco=0;
	cin>>s;
	if(k==0)
	{
		int curcount=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='a')
			{
				curcount++;
				maxco=max(maxco,curcount);
			}
			else
				curcount=0;
		}
		curcount=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='b')
			{
				curcount++;
				maxco=max(maxco,curcount);
			}
			else
				curcount=0;
		}
		cout<<maxco;
			
	}
	else
	{
		queue<int>added;
		int curcount=0;
		int tk=k;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='a')
			{
				curcount++;
				maxco=max(maxco,curcount);
			}
			else if(tk>0)
			{
				tk--;
				added.push(i);
				curcount++;
				maxco=max(maxco,curcount);
			}
			else
			{
				curcount=(i-added.front());
				added.pop();
				added.push(i);
				maxco=max(maxco,curcount);
			}
		}
		while(!added.empty())
			added.pop();
		curcount=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='b')
			{
				curcount++;
				maxco=max(maxco,curcount);
			}
			else if(k>0)
			{
				k--;
				added.push(i);
				curcount++;
				maxco=max(maxco,curcount);
			}
			else
			{
				curcount=(i-added.front());
				added.pop();
				added.push(i);
				maxco=max(maxco,curcount);
			}
		}
		cout<<maxco;

	}
}