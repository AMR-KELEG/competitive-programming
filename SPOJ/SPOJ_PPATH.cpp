//AC
#include "bits/stdc++.h"
using namespace std;
bool visited[10008]={};
bool isprime(int n)
{
	if(n%2==0)
		return 0;
	for(int d=3;d*d<=n;d+=2)
	{
		if(n%d==0)
			return 0;
	}
	return 1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int in,de,cur,steps,val;
	queue<pair<int,int> >q;
	bool found;
	while(t--)
	{
		found=0;
		memset(visited,0,sizeof visited);
		cin>>in>>de;
		q.push(pair<int,int>(in,0));

		while(!q.empty())
		{
			cur=q.front().first;
			steps=q.front().second;
			q.pop();
			//cout<<cur<<" "<<steps<<endl;
			if(cur==de)
			{
				//cout<<"FFF\n";
				found=1;
				break;
			}
			// generate
			for(int d=1;d<=1000;d*=10)
			{
				for(int add=0;add<10;add++)
				{
					val=( cur- ( (cur/d)%10) * d )+(add*d);
					if(val==cur)
						continue;
					if(!visited[val])
					{
						if(isprime(val) && val>=1000)
						{
							visited[val]=1;
							//cout<<"v "<<val<<endl;
							q.push(pair<int,int>(val,steps+1));	
						}
					}
				}
			}
			//check visited
			//check prime
		}
		if(found)
			cout<<steps<<endl;
		else
			cout<<"Impossible\n";

		while(!q.empty())
			q.pop();
	}	
}