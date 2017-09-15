//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string h,a;
	cin>>h>>a;
	map<int,int> hc,ac;
	map<int,pair<char,int> > rcards;//min player
	int n;
	cin>>n;
	int min,no;
	char te,ca;
	for(int i=0;i<n;i++)
	{
		cin>>min>>te>>no>>ca;
		//cout<<min<<" "<<te<<" "<<no<<" "<<ca<<endl;
		if(te=='h')
		{
			//home team 
			if(ca=='r')
			{
				hc[no]+=2;
				if(hc[no]==2 || hc[no]==3)
				{
					rcards[min]=pair<char,int>(te,no);
				}
			}
			else if(ca=='y')
			{
				hc[no]++;
				if(hc[no]==2)
				{
					rcards[min]=pair<char,int>(te,no);	
				}
			}
		}
		else
		{
			if(ca=='r')
			{
				ac[no]+=2;
				if(ac[no]==2 || ac[no]==3)
				{
					rcards[min]=pair<char,int>(te,no);
				}
			}
			else if(ca=='y')
			{
				ac[no]++;
				if(ac[no]==2)
				{
					rcards[min]=pair<char,int>(te,no);	
				}
			}
		}
		//cout<<te<<" NO "<<no<<" "<<" "<<hc[no]<<" "<<ac[no]<<endl;
	}
	map<int,pair<char,int> > ::iterator it=rcards.begin();
	while(it!=rcards.end())
	{
		if((*it).second.first=='h')
			cout<<h<<" ";
		else
			cout<<a<<" ";
		cout<<(*it).second.second<<" "<<(*it).first<<endl;
		it++;
	}	
}