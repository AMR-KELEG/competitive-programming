#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		std::vector<pair<int,string> > teams;
		for (int i=0;i<n;i++)
		{
			string s;
			int sc;
			cin>>s>>sc;
			teams.push_back(make_pair(sc, s));
		}
		sort(teams.rbegin(), teams.rend());
		cout<<teams[0].second<<"\n";
	}	
	return 0;
}