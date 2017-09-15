//AC
#include "bits/stdc++.h"
using namespace std;
class node
{
public:
	node * child[10];
	bool endi;
	node()
	{
		for(int i=0;i<10;i++)
			child[i]=NULL;
		endi=0;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	int n;
	string s;
	while(t--)
	{
		node root;
		cin>>n;
		bool good=1;
		while(n--)
		{
			cin>>s;
			if(!good)
				continue;
			else
			{
				node * it=&root;
				for(int i=0;i<s.size()-1;i++)
				{
					if(it->child[s[i]-'0']==NULL)
					{
						//cout<<"new ";
						it->child[s[i]-'0']=new node();
					}
					else if(it->child[s[i]-'0']->endi)
					{
						good=0;
						break;
					}
					//cout<<s[i]<<" "<<it->endi<<endl;
					it=it->child[s[i]-'0'];
				}

				if(good)
				{
					if(it->child[s[s.size()-1]-'0']==NULL)
					{
						it->child[s[s.size()-1]-'0']=new node();
					}
					else
					{
						good=0;
					}
					it=it->child[s[s.size()-1]-'0'];
					it->endi=1;
				}
			}
		}
		if(good)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}

	}	
}