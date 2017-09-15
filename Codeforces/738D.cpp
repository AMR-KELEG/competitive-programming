//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string s;
	cin>>s;
	int maxShips=0;
	std::vector<int> locations;
	int curLen=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			curLen=0;
		}
		else
		{
			curLen++;
			if(curLen%b==0)
			{
				locations.push_back(i+1);
			}
		}
	}
	int req=locations.size()+1-a;
	printf("%d\n", req);
	for(int i=0;i<req;i++)
	{
		printf("%d ", locations[i]);
	}
}