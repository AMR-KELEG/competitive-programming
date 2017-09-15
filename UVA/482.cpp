//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		getline(cin,s);
		getline(cin,s);
		getline(cin,s);
		stringstream ss(s);
		std::vector<int> indexes;
		int in;
		while(ss>>in)
		{
			indexes.push_back(in);
			// cout<<in<<" ";
		}
		// cout<<endl;
		std::vector<string> v(indexes.size());
		for(int i=0;i<indexes.size();i++)
		{
			cin>>s;
			v[indexes[i]-1]=s;
		}
		for(int i=0;i<v.size();i++)
			printf("%s\n",v[i].c_str());
		if(t)
		printf("\n");
	}	
}