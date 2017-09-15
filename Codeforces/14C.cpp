#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int x1,y1,x2,y2;
	set<pair<int,int> >points;
	map<pair<int,int>,int >pcount;
	set< pair<pair<int,int>,pair<int,int>> >lines;
	vector<pair<int,int> >temp(2);
	bool ok=1;
	for(int i=0;i<4;i++)
	{
		cin>>x1>>y1>>x2>>y2;
		temp[0]=pair<int,int>(x1,y1);
		temp[1]=pair<int,int>(x2,y2);
		if(x1==x2 && y1==y2)
			ok=0;
		sort(temp.begin(), temp.end());
		lines.insert( pair < pair<int,int>,pair<int,int> >  (temp[0],temp[1]));
		points.insert(pair<int,int>(x1,y1)); 
		points.insert(pair<int,int>(x2,y2));
		pcount[pair<int,int>(x1,y1)]++;
		pcount[pair<int,int>(x2,y2)]++;
	}
	map<pair<int,int>,int >::iterator it=pcount.begin();
	while(it!=pcount.end())
	{
		if((*it).second!=2)
		{
			ok=0;
			break;
		}
		it++;
	}
	if(ok)
	{
		if(lines.size()<4)
		{
			ok=0;
		}
		else if(points.size()<4)
		{
			ok=0;
		}
		else
		{
			set<pair<int,int> >::iterator it2=points.begin();
			pair<int,int>p1,p2,p3,p4;
			p1=*it2;
			it2++;
			p2=*it2;
			it2++;
			p3=*it2;
			it2++;
			p4=*it2;
			/*
				p2      p4
				p1      p3
			*/
			if(p1.first==p2.first && p3.first==p4.first && p1.second==p3.second && p2.second==p4.second )
			{
				;
			}
			else
			{
				ok=0;
			}
		}
	}


	if(ok)
		cout<<"YES";
	else
		cout<<"NO";



}