#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	cin>>n;
	std::vector<int> numbers(n);
	vector<pair<int,int> >output;
	map<int,vector<int> >nu_in;
	for(int i=0;i<n;i++)
	{
		cin>>numbers[i];
		nu_in[numbers[i]].push_back(i);

	}
	map<int,vector<int> >::iterator it=nu_in.begin();
	for(;it!=nu_in.end();it++)
	{
		if((*it).second.size()==1)
		{
			output.push_back(pair<int,int>((*it).first,0));
			//cout<<(*it).first<<" 0"<<endl;
			continue;
		}
		int step=(*it).second[1]-(*it).second[0];
		for(int i=2;i<(*it).second.size();i++)
		{
			if((*it).second[i]-(*it).second[i-1]!=step)
			{
				step=0;
				break;
			}
		}
		if(step!=0)
		{
			output.push_back(pair<int,int>((*it).first,step));
			//cout<<(*it).first<<" "<<step<<endl;
		}

	}
	cout<<output.size()<<endl;
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i].first<<" "<<output[i].second<<endl;
	}
	return 0;
}