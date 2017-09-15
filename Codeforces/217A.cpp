//AC
#include "bits/stdc++.h"
using namespace std;

class disset
{
public:
	set<int>x,y;
	int parent;
};
std::vector<disset> sets;
void merge(int fi,int si)
{
	disset f=sets[fi],s=sets[si];
	if(f.parent>s.parent)
	{
		swap(f,s);
		swap(fi,si);
	}
	//f is the smaller that will absorb the other set
	set<int>::iterator it=s.x.begin();
	for(;it!=s.x.end();it++)
	{
		f.x.insert(*it);
	}
	it=s.y.begin();
	for(;it!=s.y.end();it++)
	{
		f.y.insert(*it);
	}
	sets[fi]=f;
	sets.erase(sets.begin()+si);
}
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int op=-1;
	int n;
	cin>>n;
	std::vector<int> x(n),y(n);
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	disset ss;
	ss.parent=0;
	ss.x.insert(x[0]);
	ss.y.insert(y[0]); 
	sets.push_back(ss);
	int f,s;
	for(int i=1;i<n;i++)
	{
		f=-1;
		s=-1;
		for(int j=0;j<sets.size();j++)
		{		
			if(sets[j].x.find(x[i])!=sets[j].x.end() ||sets[j].y.find(y[i])!=sets[j].y.end())
			{
				sets[j].x.insert(x[i]);
				sets[j].y.insert(y[i]);
				if(f==-1)
					f=j;
				else
					s=j;
			}
		}
		if(f==-1 && s==-1)
		{
			disset ss;
			ss.parent=i;
			ss.x.insert(x[i]);
			ss.y.insert(y[i]); 
			sets.push_back(ss);
		}
		else if(f!=-1 && s!=-1)
		{
			merge(f,s);
		}
	}
	cout<<sets.size()-1;
}