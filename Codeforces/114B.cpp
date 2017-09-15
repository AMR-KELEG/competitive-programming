//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,edges;
	cin>>n>>edges;
	string s;
	bool adjmat[16][16]={};
	map<string,int>mp;
	vector<string> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=i;
		v[i]=s;
	}	
	string fi,se;
	int findex,sindex;
	for(int i=0;i<edges;i++)
	{
		cin>>fi>>se;
		findex=mp[fi];
		sindex=mp[se];
		adjmat[findex][sindex]=1;
		adjmat[sindex][findex]=1;
	}	
	std::vector<int> maxpersons,currentpersons;
	bool skip=0;
	for(unsigned int per=1;per<pow(2,n);per++)
	{
		skip=0;
		currentpersons.clear();
		//cout<<per<<" ";
		for(int shift=n-1;shift>=0;shift--)
		{
			if(1 & (per>>shift))
			{
				currentpersons.push_back(shift);
				//cout<<shift<<" ";
			}
		}

		for(int first=0;first<currentpersons.size();first++)
		{
			for(int second=first+1;second<currentpersons.size();second++)
			{
				if(adjmat[currentpersons[first]][currentpersons[second]])
				{
					second=first=currentpersons.size();
					skip=1;
					break;
				}
			}
		}
		if(skip)
		{
			//cout<<" NO \n";
			continue;
		}
		//cout<<endl;
		if(maxpersons.size()<currentpersons.size())
		maxpersons=currentpersons;
	}
	cout<<maxpersons.size()<<endl;
	std::vector<string> outputv;
	for(int i=0;i<maxpersons.size();i++)
	{
		outputv.push_back(v[maxpersons[i]]);
	}
	sort(outputv.begin(), outputv.end());
	for(int i=0;i<maxpersons.size();i++)
	{
		cout<<outputv[i]<<endl;
	}
	/*
	*/
}