//AC
#include "bits/stdc++.h"
using namespace std;
short dp[101][101]={};
short vis[101][101]={};
int n;
int m;
int curCase=0;
std::vector<string> senders;
std::vector<string> names;
std::vector<std::vector<bool> > allowed;
int solve(int messageIn,int lastTaken)
{
	if(messageIn==0)
	{
		//try taking anyone
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(allowed[0][i])
			{
				ans=max(ans,1+solve(messageIn+1,i));
			}
		}
		return dp[messageIn][lastTaken]=ans;
	}
	if(messageIn==m)
		return 0;
	if(vis[messageIn][lastTaken]==curCase)
	{
		return dp[messageIn][lastTaken];
	}
	vis[messageIn][lastTaken]=curCase;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(allowed[messageIn][i] && i!=lastTaken)
		{
			ans=max(ans,1+solve(messageIn+1,i));
		}
	}
	return dp[messageIn][lastTaken]=ans;
}

void prepareOutput(int messageIn,int lastTaken)
{
	if(messageIn==0)
	{
		//try taking anyone
		int ans=0;
		int iMax=0;
		for(int i=0;i<n;i++)
		{
			if(allowed[0][i])
			{
				if(1+solve(messageIn+1,i)>ans)
				{
					ans=1+solve(messageIn+1,i);
					iMax=i;
				}
			}
		}
		senders[messageIn]=names[iMax];
		prepareOutput(messageIn+1,iMax);
		return ;
	}
	if(messageIn==m)
		return ;
	
	int ans=0;
	int iMax=0;
	for(int i=0;i<n;i++)
	{
		if(allowed[messageIn][i] && i!=lastTaken)
		{
			if(1+solve(messageIn+1,i)>ans)
			{
				ans=1+solve(messageIn+1,i);
				iMax=i;
			}
		}
	}
	senders[messageIn]=names[iMax];
	prepareOutput(messageIn+1,iMax);
}

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		curCase++;
		cin>>n;
		names=std::vector<string> (n);
		for(int i=0;i<n;i++)
			cin>>names[i];
		cin>>m;
		senders=std::vector<string> (m);
		std::vector<string> messages(m);
		allowed=std::vector<std::vector<bool> >(m,std::vector<bool> (n,1));
		getline(cin,messages[0]);
		for(int i=0;i<m;i++)
		{
			getline(cin,messages[i]);
			int in=messages[i].find(':');
			senders[i]=messages[i].substr(0,in);
			messages[i]=messages[i].substr(in+1);
			//Find Bad values in the current sender
			if(senders[i]=="?")
			{
				bool ok=1;
				string & s=messages[i];
				for(int in=0;in<s.size();in++)
				{
					//Check chars
					if(s[in]=='.' ||s[in]==',' ||s[in]==' ' ||s[in]=='?'||s[in]=='!')
					{
						ok=1;
						continue;
					}
					else if(ok)
					{
						ok=0;	
						for(int na=0;na<n;na++)
						{
							int strInd=s.find(names[na],in);
							if(strInd==in)
							{
								//Found
								if(in+names[na].size()==s.size() || 
								s[in+names[na].size()]=='.' ||s[in+names[na].size()]==',' 
								||s[in+names[na].size()]==' ' ||s[in+names[na].size()]=='?'
								||s[in+names[na].size()]=='!')
								{
									allowed[i][na]=0;
									in+=names[na].size()-1;
									break;
								}
							}
						}
					}
				}
			}
			else
			{
				for(int in=0;in<n;in++)
				{
					if(names[in]!=senders[i])
					{
						allowed[i][in]=0;
					}
				}
			}
		}
	
		if(solve(0,0)==m)
		{
			//Prepare Output
			prepareOutput(0,0);
			for(int mes=0;mes<m;mes++)
			{
				cout<<senders[mes]<<":"<<messages[mes]<<endl;
			}
		}
		else
		{
			cout<<"Impossible\n";
		}
	}
}