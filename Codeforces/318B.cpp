#include "bits/stdc++.h"
using namespace std;
int main()
{
	string s,tem;
	cin>>s;
	//s="trueheavymetalissotruewellitisalsosoheavythatyoucanalmostfeeltheweightofmetalonyou";
	vector<int>heavy_i,metal_i;
	//tem=s;
	int he_i,me_i;
	he_i=s.find("heavy");
	while(he_i!=-1)
	{
		heavy_i.push_back(he_i);
		//tem=tem.substr(he_i+5);
		he_i=s.find("heavy",he_i+5);
	}
	//cout<<heavy_i[0]<<endl;
	//cout<<heavy_i[1]<<endl;
	//tem=s;
	me_i=s.find("metal");
	while(me_i!=-1)
	{
		metal_i.push_back(me_i);
		//tem=tem.substr(me_i+5);
		me_i=s.find("metal",me_i+5);
	}
	//cout<<metal_i.size()<<endl;
	//cout<<metal_i[0]<<endl;
	//cout<<metal_i[1]<<endl;
	long long int substrings=0;
	vector<int>::iterator it;
	for(int i=0;i<heavy_i.size();i++)
	{
		it=lower_bound(metal_i.begin(),metal_i.end(),heavy_i[i]+5);
		if(it!=metal_i.end())
		{
			substrings+=metal_i.end()-it;
			
		}
			
	}
	cout<<substrings;
	return 0;
}