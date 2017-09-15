#include "bits/stdc++.h"
using namespace std;
int fri[1005];
std::vector<vector<int> >revfri;
int pivotnode1,pivotnode2;
int dfs(int i)
{
	if(revfri[i].size()==0)
		return 0;
	int maxlen=0;
	for(int in=0;in<revfri[i].size();in++)
	{
		if(revfri[i][in]==pivotnode1 ||revfri[i][in]==pivotnode2)
			continue;
		maxlen=max(maxlen,1+dfs(revfri[i][in]));
	}
	return maxlen;
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("C-large-practice.in","r",stdin);
		freopen("c_out.txt","w",stdout);
		//freopen("C-small-practice_mostafa.in","r",stdin);
		//freopen("C-small-attempt1.in","r",stdin);
		
	#endif
	int te;
	int n;
	cin>>te;
	set<int>vis;
	set<pair<int,int> >cyclesoftwo;
	int maximumlength;
	for(int t=1;t<=te;t++)
	{
		cyclesoftwo.clear();
		maximumlength=0;
		cin>>n;
		revfri=std::vector<vector<int> > (n+5,std::vector<int> ());
		for(int i=1;i<=n;i++)
		{
			cin>>fri[i];
			revfri[fri[i]].push_back(i);
		}
		int curnode;
		int maxlen=0;
		for(int i=1;i<=n;i++)
		{
			curnode=i;
			vis.clear();
			while(vis.find(curnode)==vis.end())
			{
				vis.insert(curnode);
				curnode=fri[curnode];
			}
			if(fri[fri[curnode]]==curnode)
			{
				//cycle of length 2
				pivotnode1=curnode;
				pivotnode2=fri[curnode];
				if(cyclesoftwo.find(pair<int,int>((min(curnode,fri[curnode])),max(curnode,fri[curnode])))==cyclesoftwo.end())
				{
					cyclesoftwo.insert(pair<int,int>((min(curnode,fri[curnode])),max(curnode,fri[curnode])));
					maximumlength+=dfs(curnode)+dfs(fri[curnode]);
				}
			}
			else
			{
				//find cycle length only
				set<int>cyclenodes;
				while(cyclenodes.find(curnode)==cyclenodes.end())
				{
					cyclenodes.insert(curnode);
					curnode=fri[curnode];
				}
				maxlen=max(maxlen,(int)cyclenodes.size());	
			}
			
		}
		maxlen=max(maxlen,maximumlength+2*(int)cyclesoftwo.size());
		cout<<"Case #"<<t<<": "<<maxlen<<endl;
	}
}