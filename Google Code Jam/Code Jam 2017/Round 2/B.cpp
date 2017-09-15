#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,c,m;
		cin>>n>>c>>m;
		std::vector<int> c1(n+1,0);
		std::vector<int> c2(n+1,0);
		int p,b;
		for(int i=0;i<m;i++)
		{
			cin>>p>>b;
			if(b==1)
			{
				c1[p]++;		
			}
			else
			{
				c2[p]++;
			}
		}
		int rides=0,prom=0;
		int contr=-1;
		for(int pos=1;pos<=n;pos++)
		{
			if(c1[pos]>0 && c2[pos]>0)
			{
				//contradiction here
				contr=pos;
				//pos2 must be largest one with conflicts
				int indxOfNext=-1;
				int minV=-1;
				for(int pos2=pos+1;pos2<=n;pos2++)
				{
					if(c1[pos2]>0 && c2[pos2]>0)
					{
						if(indxOfNext==-1)
						{
							indxOfNext=pos2;
							minV=min(c1[pos2],c2[pos2]);
						}
						else if(minV<min(c1[pos2],c2[pos2]))
						{
							indxOfNext=pos2;
							minV=min(c1[pos2],c2[pos2]);	
						}
					}
				}
				if(indxOfNext==-1)
				{
					//Last contr
					contr=pos;
					break;
				}
				else if(c1[pos]<=c2[pos])
				{
					//Take c1[pos]
					int rem=min(c1[pos],c2[indxOfNext]);
					c1[pos]-=rem;
					c2[indxOfNext]-=rem;
					pos--;
					break;
				}
				if(c2[pos]<c1[pos])
				{
					//Take c1[pos]
					int rem=min(c2[pos],c1[indxOfNext]);
					c2[pos]-=rem;
					c1[indxOfNext]-=rem;
					pos--;
					break;
				}	
			}
		}
		if(contr==-1)
		{
			//find max of both to add rides
			int r1=0;
			int r2=0;
			for(int i=1;i<=n;i++)
			{
				r1+=c1[i];
				r2+=c2[i];
			}
			rides+=max(r1,r2);
		}
		else
		{
			int rem=min(c1[contr],c2[contr]);
			rides+=rem;
			prom+=min(c1[contr],c2[contr]);
			c1[contr]-=rem;
			c2[contr]-=rem;
			int r1=0;
			int r2=0;
			for(int i=1;i<=n;i++)
			{
				r1+=c1[i];
				r2+=c2[i];
			}
			rides+=max(r1,r2);
		}
		cout<<"Case #"<<t<<": "<<rides<<" "<<prom<<endl;
	}
}