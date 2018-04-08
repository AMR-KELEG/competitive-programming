//AC
#include "bits/stdc++.h"
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("A-small-practice.in","r",stdin);
		freopen("A-small-practice_out.in","w",stdout);
	#endif
	int T;
	cin>>T;
	int sear;
	set<string>servers,found;
	string temp;
	int q;
	int count;
	for(int t=1;t<=T;t++)
	{
		count=0;
		cin>>sear;
		getline(cin,temp);
		servers.clear();
		found.clear();
		for(int i=0;i<sear;i++)
		{
			getline(cin,temp);
			servers.insert(temp);
			//cout<<i+1<<" "<<temp<<endl;
		}
		cin>>q;
		getline(cin,temp);
		for(int i=0;i<q;i++)
		{
			getline(cin,temp);
			if(servers.find(temp)!=servers.end())
			{
				found.insert(temp);
				//cout<<found.size()<<endl;
				if(found.size()==sear)
				{
					count++;
					found.clear();
					found.insert(temp);
				}
			}
		}

		cout<<"Case "<<"#"<<t<<": "<<count<<endl;


	}
	
}