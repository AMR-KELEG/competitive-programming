#include "bits/stdc++.h"
using namespace std;
int vis[101][301][101][101]={};
#define state pair<int,pair<pair<int,int>,pair<int,int>>>
#define m first
#define hd second.first.first
#define ad second.first.second
#define hk second.second.first
#define ak second.second.second
#define INF 1000000000
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("C-small-attempt0.in","r",stdin);
		freopen("C-small-out.in","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int Hd,Ad,Hk,Ak,B,D;
		cin>>Hd>>Ad>>Hk>>Ak>>B>>D;
		std::queue<state> q;
		q.push({0,{{Hd,Ad},{Hk,Ak}}});
		vis[Hd][Ad][Hk][Ak]=t;
		int ans=INF;
		while(!q.empty())
		{
			state c=q.front();
			q.pop();
			if(c.ad>=c.hk)
			{
				ans=c.m+1;
				break;
			}
			if(c.ak==0)
			{
				if(B>0)
				{
					if(vis[c.hd][c.ad+B][c.hk][0]!=t)
					{
						vis[c.hd][c.ad+B][c.hk][0]=t;
						q.push({c.m+1,{{c.hd,c.ad+B},{c.hk,0}}});
					}
				}
				if(vis[c.hd][c.ad][c.hk-c.ad][0]!=t)
				{
					vis[c.hd][c.ad][c.hk-c.ad][0]=t;
					q.push({c.m+1,{{c.hd,c.ad},{c.hk-c.ad,0}}});
				}
			}
			else
			{
				// I attacked
				c.hk-=c.ad;
				if(c.hd>c.ak)
				{
					c.hd-=c.ak;
					if(vis[c.hd][c.ad][c.hk][c.ak]!=t)
					{
						vis[c.hd][c.ad][c.hk][c.ak]=t;
						q.push({c.m+1,{{c.hd,c.ad},{c.hk,c.ak}}});
					}
					c.hd+=c.ak;
				}
				c.hk+=c.ad;

				if(B>0)
				{
					if(c.hd>c.ak)
					{
						c.hd-=c.ak;
						if(vis[c.hd][c.ad+B][c.hk][c.ak]!=t)
						{
							vis[c.hd][c.ad+B][c.hk][c.ak]=t;
							q.push({c.m+1,{{c.hd,c.ad+B},{c.hk,c.ak}}});
						}
						c.hd+=c.ak;
					}
				}

				if(D>0)
				{
					int old=c.ak;
					c.ak-=D;
					c.ak=max(0,c.ak);
					if(c.hd>c.ak)
					{
						c.hd-=c.ak;
						if(vis[c.hd][c.ad][c.hk][c.ak]!=t)
						{
							vis[c.hd][c.ad][c.hk][c.ak]=t;
							q.push({c.m+1,{{c.hd,c.ad},{c.hk,c.ak}}});
						}
						c.hd+=c.ak;
					}
					c.ak=old;
				}
				
				c.hd=Hd;
				if(c.hd>c.ak)
				{
					c.hd-=c.ak;
					if(vis[c.hd][c.ad][c.hk][c.ak]!=t)
					{
						vis[c.hd][c.ad][c.hk][c.ak]=t;
						q.push({c.m+1,{{c.hd,c.ad},{c.hk,c.ak}}});
					}
				}
	
			}
		}
		cout<<"Case #"<<t<<": ";
		if(ans==INF)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<ans<<"\n";
	}	
}